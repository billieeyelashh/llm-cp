
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int max_distance1[N], max_distance2[N];

void dfs(int node, int parent) {
    max_distance1[node] = max_distance2[node] = 0;
    
    for (int child : adj[node]) {
        if (child == parent)
            continue;
        
        dfs(child, node);
        
        int distance = 1 + max_distance1[child];
        
        if (distance > max_distance1[node]) {
            max_distance2[node] = max_distance1[node];
            max_distance1[node] = distance;
        } else if (distance > max_distance2[node]) {
            max_distance2[node] = distance;
        }
    }
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
    
    for (int i = 1; i <= n; i++) {
        cout << max_distance1[i] << " ";
    }
    
    return 0;
}
