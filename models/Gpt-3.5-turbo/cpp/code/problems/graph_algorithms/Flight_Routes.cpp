
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(k, INF));
    pq.push({0, 1});
    dist[1][0] = 0;

    while (!pq.empty()) {
        long long cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] : adj[u]) {
            long long newCost = cost + w;

            if (newCost < dist[v][k - 1]) {
                dist[v][k - 1] = newCost;
                pq.push({newCost, v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    cout << endl;

    return 0;
}
