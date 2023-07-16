
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int countBeautifulPermutations(int n) {
    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    std::cin >> n;

    std::cout << countBeautifulPermutations(n) << std::endl;

    return 0;
}
