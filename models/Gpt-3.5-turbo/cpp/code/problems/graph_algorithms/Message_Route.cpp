
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // adjacency list representation

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> level(n + 1, -1); // level of each computer in the BFS traversal
    vector<int> parent(n + 1, -1); // parent of each computer in the BFS traversal

    queue<int> q;
    q.push(1); // Uolevi's computer
    level[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n) {
            // Found a valid route
            cout << level[n] << endl;
            vector<int> route;
            while (curr != -1) {
                route.push_back(curr);
                curr = parent[curr];
            }
            for (int i = route.size() - 1; i >= 0; i--) {
                cout << route[i] << " ";
            }
            cout << endl;
            return 0;
        }

        for (int next : graph[curr]) {
            if (level[next] == -1) {
                q.push(next);
                level[next] = level[curr] + 1;
                parent[next] = curr;
            }
        }
    }

    // No valid route found
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
