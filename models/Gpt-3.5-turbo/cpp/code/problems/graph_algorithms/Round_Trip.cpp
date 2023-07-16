
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> route;

bool dfs(int city, int start) {
    visited[city] = true;
    route.push_back(city);

    for (int adj : graph[city]) {
        if (adj == start) {
            return true; // Found a road back to the starting city
        }
        if (!visited[adj] && dfs(adj, start)) {
            return true; // Found a valid round trip from the adjacent city
        }
    }

    route.pop_back();
    visited[city] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, i)) {
            cout << route.size() << '\n';
            for (int city : route) {
                cout << city << ' ';
            }
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
