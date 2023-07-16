
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countWays(std::string s) {
    int n = s.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(26, 0));

    // Base case: there is only one way to reorder an empty string
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            // Exclude the case where the current character is the same as the last character
            if (j != (s[i - 1] - 'a')) {
                for (int k = 0; k < 26; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 26; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << countWays(s) << std::endl;
    return 0;
}
