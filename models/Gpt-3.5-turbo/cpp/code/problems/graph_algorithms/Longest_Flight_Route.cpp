
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flights;
vector<bool> visited;
vector<int> path;

void dfs(int city) {
    visited[city] = true;
    path.push_back(city);

    if (city == flights.size() - 1) {
        // Reached Lehmälä, print the path and return
        cout << path.size() << endl;
        for (int c : path) {
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    for (int neighbor : flights[city]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
            visited[neighbor] = false;  // Reset the visited flag for backtracking
            path.pop_back();  // Remove the last city from the path for backtracking
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    flights.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        flights[a - 1].push_back(b - 1);
    }

    dfs(0);  // Start DFS from Syrjälä (city 1)

    if (path.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
