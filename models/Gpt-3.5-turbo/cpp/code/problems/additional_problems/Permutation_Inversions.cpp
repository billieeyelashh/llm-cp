
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countPermutations(int n, int k) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            for (int l = 1; l <= i - 1 && l <= j; ++l) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::cout << countPermutations(n, k) << std::endl;

    return 0;
}
