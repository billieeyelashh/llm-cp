
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

vector<int> adj1[MAXN], adj2[MAXN];
vector<int> order1, order2;

void dfs(int u, int p, vector<int> adj[], vector<int>& order) {
    order.push_back(u);
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, order);
        }
    }
}

bool isIsomorphic(int n) {
    order1.clear();
    order2.clear();

    dfs(1, -1, adj1, order1);
    dfs(1, -1, adj2, order2);

    return (order1 == order2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        if (isIsomorphic(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
