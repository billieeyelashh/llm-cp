
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* bits[2];
};

void insert(TrieNode* root, int num) {
    TrieNode* curr = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (curr->bits[bit] == nullptr) {
            curr->bits[bit] = new TrieNode();
        }
        curr = curr->bits[bit];
    }
}

int findMaxXor(TrieNode* root, int num) {
    TrieNode* curr = root;
    int maxXor = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (curr->bits[bit ^ 1] != nullptr) {
            maxXor |= (1 << i);
            curr = curr->bits[bit ^ 1];
        } else {
            curr = curr->bits[bit];
        }
    }
    return maxXor;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    TrieNode* root = new TrieNode();
    insert(root, 0);

    int result = 0, prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix ^= nums[i];
        result = max(result, findMaxXor(root, prefix));
        insert(root, prefix);
    }

    cout << result << endl;

    return 0;
}
