
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, INF)));
    dp[1][0][0] = 0;

    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (auto [next, weight] : adj[i]) {
                dp[next][j][0] = min(dp[next][j][0], dp[i][j - 1][0] + weight);
                dp[next][j][1] = true;
            }
        }
    }

    if (dp[n][k][1]) {
        cout << dp[n][k][0] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
