
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void build_segment_tree(vector<int>& arr, vector<int>& seg_tree, int node, int start, int end) {
    if (start == end) {
        seg_tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build_segment_tree(arr, seg_tree, 2 * node, start, mid);
        build_segment_tree(arr, seg_tree, 2 * node + 1, mid + 1, end);
        seg_tree[node] = min(seg_tree[2 * node], seg_tree[2 * node + 1]);
    }
}

void update_value(vector<int>& seg_tree, int node, int start, int end, int pos, int new_val) {
    if (start == end) {
        seg_tree[node] = new_val;
    } else {
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update_value(seg_tree, 2 * node, start, mid, pos, new_val);
        } else {
            update_value(seg_tree, 2 * node + 1, mid + 1, end, pos, new_val);
        }
        seg_tree[node] = min(seg_tree[2 * node], seg_tree[2 * node + 1]);
    }
}

int query_min(vector<int>& seg_tree, int node, int start, int end, int query_start, int query_end) {
    if (query_start > end || query_end < start) {
        return INT_MAX;
    }
    if (query_start <= start && query_end >= end) {
        return seg_tree[node];
    }
    int mid = (start + end) / 2;
    int left_min = query_min(seg_tree, 2 * node, start, mid, query_start, query_end);
    int right_min = query_min(seg_tree, 2 * node + 1, mid + 1, end, query_start, query_end);
    return min(left_min, right_min);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> seg_tree(4 * n); // Assuming maximum size of seg_tree

    build_segment_tree(arr, seg_tree, 1, 0, n - 1);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update_value(seg_tree, 1, 0, n - 1, a - 1, b);
        } else if (type == 2) {
            int min_val = query_min(seg_tree, 1, 0, n - 1, a - 1, b - 1);
            cout << min_val << endl;
        }
    }

    return 0;
}
