
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
int value[MAXN];
vector<int> adj[MAXN];
int depth[MAXN], parent[MAXN];
long long subtreeSum[MAXN];

// Depth-First Search to initialize depth, parent, and subtreeSum
void dfs(int v, int p, int d) {
    depth[v] = d;
    parent[v] = p;
    subtreeSum[v] = value[v];
    
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            subtreeSum[v] += subtreeSum[u];
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1, 0);
    
    while (q--) {
        int type, s;
        cin >> type >> s;
        
        if (type == 1) {
            int x;
            cin >> x;
            subtreeSum[s] += x - value[s];
            value[s] = x;
        } else {
            cout << subtreeSum[s] << endl;
        }
    }
    
    return 0;
}
