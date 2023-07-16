
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));
    dp[1][1] = 1;
    
    for (int i = 0; i < m; ++i) {
        int y, x;
        std::cin >> y >> x;
        dp[y][x] = 0; // mark trap squares as 0
    }
    
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            if (dp[y][x] != 0) {
                dp[y][x] = (dp[y-1][x] + dp[y][x-1]) % MOD;
            }
        }
    }
    
    std::cout << dp[n][n] << std::endl;
    
    return 0;
}
