
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1));

    // Base cases
    for (int i = 1; i <= a; i++) {
        dp[i][i] = 0;
        dp[i][1] = i;
    }
    for (int j = 1; j <= b; j++) {
        dp[1][j] = j;
    }

    // Dynamic programming
    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= i/2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
            for (int k = 1; k <= j/2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}
