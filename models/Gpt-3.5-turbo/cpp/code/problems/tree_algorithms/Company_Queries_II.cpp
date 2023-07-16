
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int depth[MAXN];
int ancestors[MAXN][MAXLOG];

void dfs(int node, int parent) {
    depth[node] = depth[parent] + 1;
    ancestors[node][0] = parent;

    for (int i = 1; i < MAXLOG; i++) {
        ancestors[node][i] = ancestors[ancestors[node][i - 1]][i - 1];
    }

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (depth[b] - depth[a] >= (1 << i)) {
            b = ancestors[b][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (ancestors[a][i] != ancestors[b][i]) {
            a = ancestors[a][i];
            b = ancestors[b][i];
        }
    }

    return ancestors[a][0];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    depth[0] = -1;
    dfs(1, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}
