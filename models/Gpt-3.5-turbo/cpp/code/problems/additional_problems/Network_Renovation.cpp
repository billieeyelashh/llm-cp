
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int,int>>& newConnections) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            newConnections.push_back({node, neighbor});
            dfs(neighbor, adj, visited, newConnections);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1); // adjacency list representation
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<pair<int,int>> newConnections;

    dfs(1, adj, visited, newConnections);

    cout << newConnections.size() << "\n";
    for (auto connection : newConnections) {
        cout << connection.first << " " << connection.second << "\n";
    }

    return 0;
}
