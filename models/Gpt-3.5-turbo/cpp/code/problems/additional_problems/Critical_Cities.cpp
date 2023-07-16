
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int city) {
    visited[city] = true;
    for (int neighbor : adj[city]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
        }
    }

    cout << count << endl;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
