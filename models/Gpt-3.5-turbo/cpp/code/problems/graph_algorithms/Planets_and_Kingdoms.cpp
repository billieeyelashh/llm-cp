
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> kingdom;

void dfs(int planet, int k) {
    visited[planet] = true;
    kingdom[planet] = k;

    for (int neighbor : adj[planet]) {
        if (!visited[neighbor]) {
            dfs(neighbor, k);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);
    kingdom.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k = 0;
    for (int planet = 1; planet <= n; planet++) {
        if (!visited[planet]) {
            k++;
            dfs(planet, k);
        }
    }

    cout << k << endl;
    for (int planet = 1; planet <= n; planet++) {
        cout << kingdom[planet] << " ";
    }
    cout << endl;

    return 0;
}
