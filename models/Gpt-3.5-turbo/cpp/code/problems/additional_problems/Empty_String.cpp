
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j];
            } else {
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
