
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int subtree_size[N];

int dfs(int u, int parent) {
    subtree_size[u] = 1;
    int max_subtree_size = 0;
    
    for (int v : adj[u]) {
        if (v != parent) {
            subtree_size[u] += dfs(v, u);
            max_subtree_size = max(max_subtree_size, subtree_size[v]);
        }
    }
    
    max_subtree_size = max(max_subtree_size, n - subtree_size[u]);
    return subtree_size[u];
}

int find_centroid(int u, int parent, int n) {
    int max_subtree_size = 0;
    int centroid = u;
    
    for (int v : adj[u]) {
        if (v != parent && subtree_size[v] > n / 2) {
            return find_centroid(v, u, n);
        }
        
        if (v != parent && subtree_size[v] > max_subtree_size) {
            max_subtree_size = subtree_size[v];
            centroid = v;
        }
    }
    
    return centroid;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    cout << find_centroid(1, 0, n) << endl;
    
    return 0;
}
