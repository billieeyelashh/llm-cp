
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int pathCount[MAXN];

void dfs(int node, int parent) {
    // Increment the path count for the current node
    pathCount[node]++;

    // Traverse all the children of the current node
    for (int child : adj[node]) {
        // Skip the parent node to avoid going back
        if (child == parent) {
            continue;
        }

        // Update the path count for the child node
        pathCount[child] += pathCount[node];

        // Continue the DFS from the child node
        dfs(child, node);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read the tree edges
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Perform DFS from the root node (node 1)
    dfs(1, 0);

    // Read and process the paths
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // Print the path count for the starting node of each path
        cout << pathCount[a] << " ";
    }

    cout << endl;

    return 0;
}
