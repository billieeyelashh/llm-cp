
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100001;
const int MAX_ALPHA = 26;

struct Node {
    Node* children[MAX_ALPHA];
    Node* parent;
    Node* suffixLink;
    bool isWord;

    Node() {
        for (int i = 0; i < MAX_ALPHA; i++) {
            children[i] = nullptr;
        }
        parent = nullptr;
        suffixLink = nullptr;
        isWord = false;
    }
};

class AhoCorasick {
private:
    Node* root;

    void buildSuffixLinks() {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();

            for (int i = 0; i < MAX_ALPHA; i++) {
                if (currentNode->children[i] != nullptr) {
                    Node* childNode = currentNode->children[i];

                    if (currentNode == root) {
                        childNode->suffixLink = root;
                    } else {
                        Node* suffixNode = currentNode->suffixLink;
                        while (suffixNode != root && suffixNode->children[i] == nullptr) {
                            suffixNode = suffixNode->suffixLink;
                        }
                        if (suffixNode->children[i] != nullptr) {
                            suffixNode = suffixNode->children[i];
                        }
                        childNode->suffixLink = suffixNode;
                    }

                    childNode->isWord = childNode->isWord || childNode->suffixLink->isWord;

                    q.push(childNode);
                }
            }
        }
    }

public:
    AhoCorasick() {
        root = new Node();
    }

    void addPattern(const string& pattern) {
        Node* currentNode = root;

        for (char c : pattern) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new Node();
                currentNode->children[index]->parent = currentNode;
            }
            currentNode = currentNode->children[index];
        }

        currentNode->isWord = true;
    }

    vector<bool> findPatterns(const string& text) {
        vector<bool> occurrences;
        Node* currentNode = root;

        for (char c : text) {
            int index = c - 'a';

            while (currentNode != root && currentNode->children[index] == nullptr) {
                currentNode = currentNode->suffixLink;
            }

            if (currentNode->children[index] != nullptr) {
                currentNode = currentNode->children[index];
            }

            if (currentNode->isWord) {
                occurrences.push_back(true);
            } else {
                occurrences.push_back(false);
            }
        }

        return occurrences;
    }
};

int main() {
    string text;
    cin >> text;

    int k;
    cin >> k;

    AhoCorasick ahoCorasick;

    for (int i = 0; i < k; i++) {
        string pattern;
        cin >> pattern;
        ahoCorasick.addPattern(pattern);
    }

    vector<bool> occurrences = ahoCorasick.findPatterns(text);

    for (bool isFound : occurrences) {
        cout << (isFound ? "YES" : "NO") << endl;
    }

    return 0;
}
