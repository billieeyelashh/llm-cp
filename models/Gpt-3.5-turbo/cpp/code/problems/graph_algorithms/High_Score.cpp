
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> tunnels(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        tunnels[a].push_back({b, x});
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (auto tunnel : tunnels[u]) {
                int v = tunnel.first;
                int score = tunnel.second;
                dist[v] = max(dist[v], dist[u] + score);
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (int u = 1; u <= n; ++u) {
        for (auto tunnel : tunnels[u]) {
            int v = tunnel.first;
            int score = tunnel.second;
            if (dist[v] < dist[u] + score) {
                hasNegativeCycle = true;
                break;
            }
        }
    }

    if (hasNegativeCycle) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }

    return 0;
}
