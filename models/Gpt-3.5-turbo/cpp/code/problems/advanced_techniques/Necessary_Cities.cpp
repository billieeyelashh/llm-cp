
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
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
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    vector<int> necessaryCities;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            necessaryCities.push_back(i);
        }
    }

    cout << necessaryCities.size() << endl;
    for (int city : necessaryCities) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
