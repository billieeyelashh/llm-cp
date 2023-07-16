
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countWays(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                dp[i][j] = 1;
            } else if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 2]) % MOD;
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << countWays(n, m) << endl;

    return 0;
}
