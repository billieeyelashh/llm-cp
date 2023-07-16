
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int cnt[MAXN];
long long ans[MAXN];

void dfs(int node, int parent) {
    cnt[node] = 1;
    ans[node] = 0;

    for (int adjNode : adj[node]) {
        if (adjNode == parent) continue;

        dfs(adjNode, node);

        cnt[node] += cnt[adjNode];
        ans[node] += ans[adjNode] + cnt[adjNode];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
