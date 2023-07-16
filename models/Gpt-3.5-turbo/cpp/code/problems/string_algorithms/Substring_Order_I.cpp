
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
};

TrieNode* createNode() {
    TrieNode* newNode = new TrieNode();
    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}

void insert(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

void dfs(TrieNode* node, priority_queue<string, vector<string>, greater<string>>& pq, int& count, int k) {
    if (node == nullptr) {
        return;
    }
    if (node->isEndOfWord) {
        count++;
        if (count == k) {
            return;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            dfs(node->children[i], pq, count, k);
            if (count == k) {
                pq.push(string(1, c));
            }
        }
    }
}

string findKthSmallestSubstring(const string& s, int k) {
    TrieNode* root = createNode();
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            insert(root, s.substr(i, j - i + 1));
        }
    }
    priority_queue<string, vector<string>, greater<string>> pq;
    int count = 0;
    dfs(root, pq, count, k);
    return pq.top();
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << findKthSmallestSubstring(s, k) << endl;
    return 0;
}
