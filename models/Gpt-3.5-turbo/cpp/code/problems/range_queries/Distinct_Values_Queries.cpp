
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 2e5;
int n, q;
int arr[MAX_N + 1];
vector<set<int>> segTree(4 * MAX_N);

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        segTree[node].insert(arr[start]);
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    segTree[node].insert(segTree[2 * node].begin(), segTree[2 * node].end());
    segTree[node].insert(segTree[2 * node + 1].begin(), segTree[2 * node + 1].end());
}

// Function to answer a query
int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return 0;

    if (start >= left && end <= right)
        return segTree[node].size();

    int mid = (start + end) / 2;
    int leftCount = query(2 * node, start, mid, left, right);
    int rightCount = query(2 * node + 1, mid + 1, end, left, right);

    return leftCount + rightCount;
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << endl;
    }

    return 0;
}
