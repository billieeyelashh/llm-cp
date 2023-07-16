
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> outdegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        outdegree[a]++;
        outdegree[b]++;
    }

    queue<int> q;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (outdegree[i] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (outdegree[i] > 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                cout << node << " " << neighbor << endl;
                outdegree[neighbor]--;
                if (outdegree[neighbor] % 2 == 0) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    return 0;
}
