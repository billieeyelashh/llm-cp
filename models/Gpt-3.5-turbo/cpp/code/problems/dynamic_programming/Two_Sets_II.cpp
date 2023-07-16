
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    int totalSum = (n * (n + 1)) / 2;

    // Initialize dp array
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(totalSum + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    int answer = dp[n][totalSum / 2];
    std::cout << answer << std::endl;

    return 0;
}
