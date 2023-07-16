
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;
vector<int> distinctColors;

void dfs(int node, int parent) {
    set<int> colorSet;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    colorSet.insert(colors[node-1]);
    for (int child : adj[node]) {
        if (child != parent) {
            for (int color : distinctColors[child-1]) {
                colorSet.insert(color);
            }
        }
    }
    distinctColors[node-1] = colorSet.size();
}

int main() {
    int n;
    cin >> n;
    
    colors.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    distinctColors.resize(n);
    dfs(1, -1);
    
    for (int i = 0; i < n; i++) {
        cout << distinctColors[i] << " ";
    }
    cout << endl;
    
    return 0;
}
