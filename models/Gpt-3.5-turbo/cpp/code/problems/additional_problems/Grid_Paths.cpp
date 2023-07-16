
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

            for (int k = 0; k < m; k++) {
                int trapY, trapX;
                std::cin >> trapY >> trapX;

                if (trapY == i && trapX == j) {
                    dp[i][j] = 0;
                    break;
                }
            }
        }
    }

    std::cout << dp[n][n] << std::endl;

    return 0;
}
