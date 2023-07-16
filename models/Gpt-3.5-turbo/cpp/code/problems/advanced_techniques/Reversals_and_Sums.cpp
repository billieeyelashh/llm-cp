
#include <iostream>
#include <vector>

using namespace std;

vector<int> segTree;
vector<bool> lazy;

void buildTree(const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, 2 * node, start, mid);
    buildTree(arr, 2 * node + 1, mid + 1, end);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

void updateTree(int node, int start, int end, int l, int r) {
    if (lazy[node]) {
        segTree[node] = (end - start + 1) - segTree[node];
        if (start != end) {
            lazy[2 * node] = !lazy[2 * node];
            lazy[2 * node + 1] = !lazy[2 * node + 1];
        }
        lazy[node] = false;
    }

    if (start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) {
        segTree[node] = (end - start + 1) - segTree[node];
        if (start != end) {
            lazy[2 * node] = !lazy[2 * node];
            lazy[2 * node + 1] = !lazy[2 * node + 1];
        }
        return;
    }

    int mid = (start + end) / 2;
    updateTree(2 * node, start, mid, l, r);
    updateTree(2 * node + 1, mid + 1, end, l, r);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int queryTree(int node, int start, int end, int l, int r) {
    if (lazy[node]) {
        segTree[node] = (end - start + 1) - segTree[node];
        if (start != end) {
            lazy[2 * node] = !lazy[2 * node];
            lazy[2 * node + 1] = !lazy[2 * node + 1];
        }
        lazy[node] = false;
    }

    if (start > r || end < l) {
        return 0;
    }

    if (start >= l && end <= r) {
        return segTree[node];
    }

    int mid = (start + end) / 2;
    int leftSum = queryTree(2 * node, start, mid, l, r);
    int rightSum = queryTree(2 * node + 1, mid + 1, end, l, r);
    return leftSum + rightSum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    segTree.resize(4 * n);
    lazy.resize(4 * n, false);

    buildTree(arr, 1, 1, n);

    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            updateTree(1, 1, n, a, b);
        } else if (t == 2) {
            int sum = queryTree(1, 1, n, a, b);
            cout << sum << endl;
        }
    }

    return 0;
}
