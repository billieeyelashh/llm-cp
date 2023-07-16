
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v, int& minConnections) {
    visited[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            minConnections++;
            dfs(u, minConnections);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int minConnections = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, minConnections);
        }
    }

    cout << minConnections << endl;

    return 0;
}
