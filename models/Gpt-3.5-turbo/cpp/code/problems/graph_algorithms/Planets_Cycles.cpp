
#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, vector<int>& teleportations, const vector<vector<int>>& adj) {
    if (teleportations[current] != -1) {
        return;
    }

    teleportations[current] = 0;
    dfs(adj[current], teleportations, adj);
    teleportations[current] = teleportations[adj[current]] + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> t(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back(t[i]);
    }

    vector<int> teleportations(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (teleportations[i] == -1) {
            dfs(i, teleportations, adj);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << teleportations[i] << " ";
    }
    cout << endl;

    return 0;
}
