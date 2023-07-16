
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++) {
        if (x[0] == 0 || x[0] == j) {
            dp[1][j] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == 0 || x[i - 1] == j) {
                for (int k = max(1, j - 1); k <= min(m, j + 1); k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
