
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string string1, string2;
    cin >> string1 >> string2;

    int n = string1.length();
    int m = string2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (string1[i - 1] == string2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
