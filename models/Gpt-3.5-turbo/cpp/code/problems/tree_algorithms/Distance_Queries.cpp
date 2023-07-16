
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_LOG = 20;

vector<int> adj[MAX_N];
int depth[MAX_N];
int parent[MAX_N][MAX_LOG];

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;

    for (int i = 1; i < MAX_LOG; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
    }

    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            a = parent[a][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int distance(int a, int b) {
    int l = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[l];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << distance(a, b) << "\n";
    }

    return 0;
}
