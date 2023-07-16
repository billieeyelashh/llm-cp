
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> maxDist;

void dfs(int u, int prev, int dist) {
    visited[u] = true;
    maxDist[u] = dist;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u, dist + 1);
        }
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    adj.resize(n + 1);
    visited.resize(n + 1, false);
    maxDist.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 0);

    vector<int> offices;
    for (int i = 1; i <= n; i++) {
        if (maxDist[i] >= d) {
            offices.push_back(i);
        }
    }

    cout << offices.size() << endl;
    for (int office : offices) {
        cout << office << " ";
    }
    cout << endl;

    return 0;
}
