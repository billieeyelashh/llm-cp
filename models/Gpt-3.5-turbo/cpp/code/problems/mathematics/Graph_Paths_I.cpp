
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[1][0] = 1;

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (int u : adj[i]) {
                dp[i][j] = (dp[i][j] + dp[u][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
