
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> route;

void dfs(int crossing) {
    visited[crossing] = true;
    route.push_back(crossing);

    for (int i = 0; i < adj[crossing].size(); i++) {
        int nextCrossing = adj[crossing][i];

        if (!visited[nextCrossing]) {
            dfs(nextCrossing);
            route.push_back(crossing); // backtrack after exploring the next crossing
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    if (route.size() == n) {
        for (int i = 0; i < route.size(); i++) {
            cout << route[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
