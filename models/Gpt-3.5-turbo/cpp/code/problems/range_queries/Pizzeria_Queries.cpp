
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Segment tree node structure
struct Node {
    int minPrice;
};

// Build segment tree
void build(vector<int>& prices, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node].minPrice = prices[start];
        return;
    }

    int mid = (start + end) / 2;
    build(prices, tree, 2 * node, start, mid);
    build(prices, tree, 2 * node + 1, mid + 1, end);

    tree[node].minPrice = min(tree[2 * node].minPrice, tree[2 * node + 1].minPrice);
}

// Update pizza price in segment tree
void update(vector<Node>& tree, int node, int start, int end, int idx, int price) {
    if (start == end) {
        tree[node].minPrice = price;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(tree, 2 * node, start, mid, idx, price);
    } else {
        update(tree, 2 * node + 1, mid + 1, end, idx, price);
    }

    tree[node].minPrice = min(tree[2 * node].minPrice, tree[2 * node + 1].minPrice);
}

// Query minimum pizza price in segment tree
int query(vector<Node>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return INT_MAX;
    }

    if (left <= start && end <= right) {
        return tree[node].minPrice;
    }

    int mid = (start + end) / 2;
    int leftPrice = query(tree, 2 * node, start, mid, left, right);
    int rightPrice = query(tree, 2 * node + 1, mid + 1, end, left, right);

    return min(leftPrice, rightPrice);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    vector<Node> tree(4 * n);
    build(prices, tree, 1, 0, n - 1);

    while (q--) {
        int type, k, x;
        cin >> type >> k;
        
        if (type == 1) {
            cin >> x;
            update(tree, 1, 0, n - 1, k - 1, x);
        } else {
            cout << query(tree, 1, 0, n - 1, k - 1, k - 1) << endl;
        }
    }

    return 0;
}
