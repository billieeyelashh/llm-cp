
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int disc[MAXN], low[MAXN];
bool inStack[MAXN];
stack<int> st;
vector<vector<int>> sccs;
int timer = 0;

void dfs(int node) {
    disc[node] = low[node] = ++timer;
    st.push(node);
    inStack[node] = true;

    for (int neighbor : adj[node]) {
        if (disc[neighbor] == 0) {
            dfs(neighbor);
            low[node] = min(low[node], low[neighbor]);
        } else if (inStack[neighbor]) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }

    if (low[node] == disc[node]) {
        vector<int> scc;
        while (true) {
            int curr = st.top();
            st.pop();
            inStack[curr] = false;
            scc.push_back(curr);
            if (curr == node) break;
        }
        sccs.push_back(scc);
    }
}

void findSCCs(int n) {
    for (int i = 1; i <= n; ++i) {
        if (disc[i] == 0) {
            dfs(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findSCCs(n);

    if (sccs.size() == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (const vector<int>& scc : sccs) {
        for (int node : scc) {
            cout << node << " " << scc[0] << endl;
        }
    }
}

int main() {
    solve();

    return 0;
}
