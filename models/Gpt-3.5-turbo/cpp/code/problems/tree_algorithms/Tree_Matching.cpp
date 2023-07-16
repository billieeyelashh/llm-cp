
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> includeCount, excludeCount;

void dfs(int node, int parent) {
    includeCount[node] = 0;
    excludeCount[node] = 0;

    for (int child : adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node);
        includeCount[node] += excludeCount[child];
        excludeCount[node] += max(includeCount[child], excludeCount[child]);
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    includeCount.resize(n + 1);
    excludeCount.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << max(includeCount[1], excludeCount[1]) << endl;

    return 0;
}
