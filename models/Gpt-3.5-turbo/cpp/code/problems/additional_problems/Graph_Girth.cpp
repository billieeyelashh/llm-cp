
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int girth = -1;
    for (int start = 1; start <= n; ++start) {
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, numeric_limits<int>::max());

        queue<int> q;
        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);
                } else if (distance[neighbor] >= 2) {
                    girth = (girth == -1) ? distance[curr] + distance[neighbor] + 1 : min(girth, distance[curr] + distance[neighbor] + 1);
                }
            }
        }
    }

    cout << girth << endl;

    return 0;
}
