
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
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

    vector<int> disconnected_cities;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            disconnected_cities.push_back(i);
            dfs(i);
        }
    }

    int k = disconnected_cities.size();
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << disconnected_cities[i] << " " << disconnected_cities[(i + 1) % k] << endl;
    }

    return 0;
}
