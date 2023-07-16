
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a node in the segment tree
struct Node {
    int sum;
};

// Function to build the segment tree
void buildSegmentTree(vector<int>& arr, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node].sum = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(arr, tree, 2 * node, start, mid);
        buildSegmentTree(arr, tree, 2 * node + 1, mid + 1, end);
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }
}

// Function to update the value at position k in the array and segment tree
void updateValue(vector<int>& arr, vector<Node>& tree, int node, int start, int end, int k, int u) {
    if (start == end) {
        arr[k] = u;
        tree[node].sum = u;
    } else {
        int mid = (start + end) / 2;
        if (k >= start && k <= mid) {
            updateValue(arr, tree, 2 * node, start, mid, k, u);
        } else {
            updateValue(arr, tree, 2 * node + 1, mid + 1, end, k, u);
        }
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }
}

// Function to find the sum of values in the range [a, b]
int querySum(vector<Node>& tree, int node, int start, int end, int a, int b) {
    if (start > b || end < a) {
        return 0;
    } else if (start >= a && end <= b) {
        return tree[node].sum;
    } else {
        int mid = (start + end) / 2;
        int leftSum = querySum(tree, 2 * node, start, mid, a, b);
        int rightSum = querySum(tree, 2 * node + 1, mid + 1, end, a, b);
        return leftSum + rightSum;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<Node> tree(4 * n);
    buildSegmentTree(arr, tree, 1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;
            updateValue(arr, tree, 1, 0, n - 1, k - 1, u);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << querySum(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }

    return 0;
}
