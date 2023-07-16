
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> values;
vector<int> fenwick;

// Function to update the Fenwick tree
void update(int idx, int val) {
    while (idx < fenwick.size()) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

// Function to calculate the prefix sum up to idx in the Fenwick tree
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}

// Function to calculate the sum of values on the path from the root to node s
int sumOnPath(int s) {
    return query(s) - query(s - 1);
}

// Depth-first search to construct the tree
void dfs(int node, int parent) {
    for (int child : tree[node]) {
        if (child != parent) {
            update(child, values[child]);
            dfs(child, node);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    tree.resize(n + 1);
    values.resize(n + 1);
    fenwick.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Construct the Fenwick tree and perform queries
    dfs(1, 0);

    while (q--) {
        int type, s;
        cin >> type >> s;

        if (type == 1) {
            int x;
            cin >> x;
            update(s, x - values[s]);
            values[s] = x;
        } else {
            cout << sumOnPath(s) << endl;
        }
    }

    return 0;
}
