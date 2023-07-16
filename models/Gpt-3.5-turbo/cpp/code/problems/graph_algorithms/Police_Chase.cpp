
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    bfs(adj, visited, 1); // Starting BFS from the bank crossing
    vector<bool> reachableFromBank = visited;

    visited.assign(n + 1, false);
    bfs(adj, visited, n); // Starting BFS from the harbor crossing
    vector<bool> reachableFromHarbor = visited;

    vector<pair<int, int>> streetsToClose;
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            if (!reachableFromBank[i] && !reachableFromHarbor[neighbor]) {
                streetsToClose.push_back({i, neighbor});
            }
        }
    }

    cout << streetsToClose.size() << endl;
    for (auto street : streetsToClose) {
        cout << street.first << " " << street.second << endl;
    }

    return 0;
}
