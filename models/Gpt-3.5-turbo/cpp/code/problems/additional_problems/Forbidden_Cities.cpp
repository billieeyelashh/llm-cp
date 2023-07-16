
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int target, int forbidden, bool& found) {
    if (current == target) {
        found = true;
        return;
    }

    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor] && neighbor != forbidden) {
            dfs(graph, visited, neighbor, target, forbidden, found);
        }
    }
}

string findRoute(vector<vector<int>>& graph, int a, int b, int c) {
    vector<bool> visited(graph.size(), false);
    bool found = false;

    dfs(graph, visited, a, b, c, found);

    return found ? "YES" : "NO";
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n + 1);  // +1 to handle 1-based indexing

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << findRoute(graph, a, b, c) << endl;
    }

    return 0;
}
