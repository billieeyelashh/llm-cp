
#include <iostream>
#include <unordered_set>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
};

void insertSubstring(TrieNode* root, const string& str) {
    TrieNode* curr = root;
    for (char c : str) {
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
}

int countDistinctSubstrings(const string& s) {
    TrieNode* root = new TrieNode();
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            string substring = s.substr(i, j - i + 1);
            insertSubstring(root, substring);
            counter++;
        }
    }
    return counter;
}

int main() {
    string s;
    cin >> s;
    for (int i = 1; i <= s.length(); i++) {
        cout << countDistinctSubstrings(s.substr(0, i)) << " ";
    }
    cout << endl;
    return 0;
}
