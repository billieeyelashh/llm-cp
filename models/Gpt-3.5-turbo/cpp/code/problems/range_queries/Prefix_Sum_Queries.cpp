
const int INF = 1e9; // Infinity value for empty ranges

vector<int> tree; // Segment tree

void build(int node, int start, int end, const vector<int>& values) {
    if (start == end) {
        tree[node] = values[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, values);
        build(2 * node + 1, mid + 1, end, values);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

void buildSegmentTree(const vector<int>& values) {
    int n = values.size();
    tree.resize(4 * n); // Size of the segment tree

    build(1, 0, n - 1, values);
}
