
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map<char, Node*> children;
};

Node* createNode() {
    Node* node = new Node;
    return node;
}

void insertSuffix(Node* root, const string& str, int start) {
    Node* current = root;
    for (int i = start; i < str.size(); i++) {
        char ch = str[i];
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = createNode();
        }
        current = current->children[ch];
    }
}

int countDistinctSubstrings(const string& str) {
    Node* root = createNode();
    for (int i = 0; i < str.size(); i++) {
        insertSuffix(root, str, i);
    }
    return root->children.size();
}

int main() {
    string str;
    cin >> str;
    int result = countDistinctSubstrings(str);
    cout << result << endl;
    return 0;
}
