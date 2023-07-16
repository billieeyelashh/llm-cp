
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Route {
    int destination;
    int maxParcels;
    int costPerParcel;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Route>> adjList(n);
    for (int i = 0; i < m; ++i) {
        int a, b, r, c;
        cin >> a >> b >> r >> c;
        adjList[a-1].push_back({b-1, r, c});
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    dp[0][0] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int city = pq.top().second.first;
        int parcels = pq.top().second.second;
        pq.pop();

        if (cost > dp[city][parcels]) {
            continue;
        }

        for (const auto& route : adjList[city]) {
            int nextCity = route.destination;
            int nextParcels = parcels + 1;
            int nextCost = cost + route.costPerParcel;

            if (nextParcels <= k && nextCost < dp[nextCity][nextParcels]) {
                dp[nextCity][nextParcels] = nextCost;
                pq.push({nextCost, {nextCity, nextParcels}});
            }
        }
    }

    int minCost = INF;
    for (int i = 0; i <= k; ++i) {
        minCost = min(minCost, dp[n-1][i]);
    }

    if (minCost == INF) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}
