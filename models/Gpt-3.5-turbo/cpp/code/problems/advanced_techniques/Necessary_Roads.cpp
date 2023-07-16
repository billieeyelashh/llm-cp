
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN+1];
int disc[MAXN+1], low[MAXN+1];
bool inStack[MAXN+1];
stack<int> st;
int timer = 0;
vector<pair<int, int>> necessaryRoads;

void dfs(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            inStack[v] = false;
            if (u != v) {
                necessaryRoads.push_back({u, v});
            }
        } while (u != v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (disc[i] == 0) {
            dfs(i);
        }
    }

    cout << necessaryRoads.size() << endl;
    for (auto road : necessaryRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}
