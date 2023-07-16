
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> team;
bool possible = true;

void dfs(int v, int t) {
    if (team[v] != 0) {
        if (team[v] != t) {
            possible = false;
        }
        return;
    }
    
    team[v] = t;
    
    for (int u : adj[v]) {
        dfs(u, 3 - t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    team.resize(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
