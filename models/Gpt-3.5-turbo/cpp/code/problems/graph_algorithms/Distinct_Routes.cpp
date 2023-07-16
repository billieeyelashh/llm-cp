
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i + 1});
        adj[b].push_back({a, i + 1});
    }
    
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (parent[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    int k = dist[n];
    cout << k << "\n";
    
    vector<vector<int>> routes(k);
    
    int curr = n;
    for (int i = k - 1; i >= 0; i--) {
        routes[i].push_back(curr);
        int prev = parent[curr];
        if (prev != -1) {
            routes[i].push_back(prev);
            curr = prev;
        }
    }
    
    for (const auto& route : routes) {
        cout << route.size() << " ";
        for (int r : route) {
            cout << r << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
