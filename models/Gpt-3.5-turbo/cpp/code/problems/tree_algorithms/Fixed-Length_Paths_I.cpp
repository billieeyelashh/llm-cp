
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj; // adjacency list representation of the tree
vector<int> visited; // visited array to keep track of visited nodes
int pathCount = 0; // counter variable to count the paths

void dfs(int node, int pathLength) {
    visited[node] = true;
    
    if (pathLength == k) {
        pathCount++;
        return;
    }
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, pathLength + 1);
        }
    }
    
    visited[node] = false; // backtrack: mark the current node as unvisited
}

int main() {
    int n, k;
    cin >> n >> k;
    
    // Initialize the adjacency list and visited array
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    // Read the edges of the tree
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Start the DFS from any node
    dfs(1, 0);
    
    cout << pathCount << endl;
    
    return 0;
}
