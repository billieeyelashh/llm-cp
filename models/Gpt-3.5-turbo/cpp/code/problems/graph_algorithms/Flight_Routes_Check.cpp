
#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list to represent the flights

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<bool> visited(n + 1, false); // array to keep track of visited cities
    dfs(1, adj, visited);

    // Check if all cities are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << "1 " << i << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
