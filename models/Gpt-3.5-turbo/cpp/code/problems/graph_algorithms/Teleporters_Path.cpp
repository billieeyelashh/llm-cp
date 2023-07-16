
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> teleporters;
vector<int> path;

bool dfs(int level) {
    visited[level] = true;
    path.push_back(level);

    if (level == adj.size() - 1) {
        return true; // reached the last level, found a solution
    }

    for (int next : adj[level]) {
        if (!visited[next]) {
            // check if the teleporter is used
            bool used = false;
            for (auto p : teleporters) {
                if ((p.first == level && p.second == next) || (p.first == next && p.second == level)) {
                    used = true;
                    break;
                }
            }

            if (!used) {
                // mark the teleporter as used
                teleporters.push_back({level, next});

                if (dfs(next)) {
                    return true; // found a solution
                }

                // backtrack: mark the teleporter as unused
                teleporters.pop_back();
            }
        }
    }

    // backtrack: mark the level as unvisited
    visited[level] = false;
    path.pop_back();

    return false; // no solution from this level
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (dfs(1)) {
        for (int level : path) {
            cout << level << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
