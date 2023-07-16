
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> adj[100001];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int oddDegreeCount = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            oddDegreeCount++;
        }
    }

    if (oddDegreeCount > 2) {
        cout << "0\n";
        return 0;
    }

    int connectedComponents = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    if (connectedComponents > 1) {
        cout << "0\n";
        return 0;
    }

    if (oddDegreeCount == 2) {
        cout << "1\n";
        return 0;
    }

    long long ans = 1;
    for (int i = 0; i < m; i++) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << "\n";

    return 0;
}
