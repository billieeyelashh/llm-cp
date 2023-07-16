
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int cur, int target) {
    visited[cur] = true;
    
    if (cur == target) {
        return;
    }
    
    for (int neighbor : adj[cur]) {
        if (!visited[neighbor]) {
            dfs(neighbor, target);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    adj.resize(n + 1);
    visited.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        // Reset visited array for each query
        fill(visited.begin(), visited.end(), false);
        
        dfs(a, b);
        
        if (visited[b]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
