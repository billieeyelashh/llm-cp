
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int farthestNode, maxDistance;

void dfs(int node, int distance) {
    visited[node] = true;
    if (distance > maxDistance) {
        maxDistance = distance;
        farthestNode = node;
    }
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, distance + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    farthestNode = 0;
    maxDistance = 0;
    dfs(1, 0); // Perform DFS from any node (e.g., node 1)

    visited.assign(n + 1, false);
    maxDistance = 0;
    dfs(farthestNode, 0); // Perform DFS from the farthest node

    cout << maxDistance << endl;

    return 0;
}
