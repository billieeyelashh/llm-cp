
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int outcome = 1; outcome <= 6; ++outcome) {
            if (i - outcome >= 0) {
                dp[i] = (dp[i] + dp[i - outcome]) % MOD;
            }
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}
