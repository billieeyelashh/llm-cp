
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n;
    string pattern;
    cin >> pattern;
    m = pattern.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                if (j > 0 && ch != pattern[j - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                } else if (j > 0 && ch == pattern[j - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
