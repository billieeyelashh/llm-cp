
#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;

void build(vector<long long>& arr, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int l, int r, int x, int type) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        if (type == 1)
            tree[v] += x;
        else
            tree[v] = x * (r - l + 1);
    } else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), x, type);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x, type);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    tree.resize(4 * n);
    build(arr, 1, 0, n - 1);

    while (q--) {
        int type, a, b, x;
        cin >> type >> a >> b;
        if (type == 1 || type == 2) {
            cin >> x;
            update(1, 0, n - 1, a - 1, b - 1, x, type);
        } else {
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }

    return 0;
}
