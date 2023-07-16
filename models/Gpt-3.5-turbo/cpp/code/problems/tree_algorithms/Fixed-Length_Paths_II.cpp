
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int counter[MAXN];

void dfs(int u, int parent, int depth, int k1, int k2) {
    if (depth >= k1 && depth <= k2) {
        counter[u]++;
    }

    if (depth < k2) {
        counter[u] += counter[parent];
    }

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, depth + 1, k1, k2);
        }
    }
}

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0, k1, k2);

    int totalPaths = 0;
    for (int i = 1; i <= n; i++) {
        totalPaths += counter[i];
    }

    cout << totalPaths << endl;

    return 0;
}
