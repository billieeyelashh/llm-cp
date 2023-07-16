
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        int y, x;
        std::cin >> y >> x;
        dp[y-1][x-1] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    std::cout << dp[n-1][n-1] << std::endl;

    return 0;
}
