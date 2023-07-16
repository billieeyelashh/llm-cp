
#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

struct TrieNode {
    TrieNode* children[MAX_CHAR];
    bool isEndOfWord;
    int count;

    TrieNode() {
        for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        count = 0;
    }
};

void insertSuffix(TrieNode* root, string suffix) {
    TrieNode* curr = root;
    for (char ch : suffix) {
        int index = ch - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
        curr->count++;
    }
    curr->isEndOfWord = true;
}

string findKthSmallestSubstring(TrieNode* root, int k) {
    string result;
    TrieNode* curr = root;
    while (k > 0) {
        for (int i = 0; i < MAX_CHAR; i++) {
            if (curr->children[i] != nullptr) {
                TrieNode* next = curr->children[i];
                if (next->count >= k) {
                    result += 'a' + i;
                    curr = next;
                    break;
                } else {
                    k -= next->count;
                }
            }
        }
    }
    return result;
}

string findKthSmallestSubstring(string s, int k) {
    TrieNode* root = new TrieNode();
    int n = s.length();
    for (int i = 0; i < n; i++) {
        string suffix = s.substr(i);
        insertSuffix(root, suffix);
    }
    return findKthSmallestSubstring(root, k);
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << findKthSmallestSubstring(s, k) << endl;
    return 0;
}
