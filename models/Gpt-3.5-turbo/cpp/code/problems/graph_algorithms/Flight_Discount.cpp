
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> minCost(n + 1, INF);
    vector<int> minCostAfterCoupon(n + 1, INF);
    minCost[1] = minCostAfterCoupon[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost > minCostAfterCoupon[u]) {
            continue;
        }

        for (auto p : adj[u]) {
            int v = p.first;
            int flightCost = p.second;

            int totalCost = cost + flightCost;
            if (totalCost < minCost[v]) {
                minCostAfterCoupon[v] = min(minCostAfterCoupon[v], minCost[v]);
                minCost[v] = totalCost;
                pq.push({totalCost, v});
            } else if (totalCost < minCostAfterCoupon[v]) {
                minCostAfterCoupon[v] = totalCost;
                pq.push({totalCost, v});
            }
        }
    }

    cout << min(minCost[n], minCostAfterCoupon[n]) << endl;

    return 0;
}
