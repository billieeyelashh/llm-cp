
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] * (i*i - (i-1)*(i-1))) % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
