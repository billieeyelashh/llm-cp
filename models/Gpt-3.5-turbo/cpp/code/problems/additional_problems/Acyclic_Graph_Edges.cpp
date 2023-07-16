
#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, ostream& out) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            out << node + 1 << " " << neighbor + 1 << "\n";
            dfs(neighbor, graph, visited, out);
            out << neighbor + 1 << " " << node + 1 << "\n";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<bool> visited(n, false);

    dfs(0, graph, visited, cout);

    return 0;
}
