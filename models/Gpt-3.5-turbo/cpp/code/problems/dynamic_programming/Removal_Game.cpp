
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (i == j) {
                dp[i][j] = x[i];
            } else {
                int option1 = x[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int option2 = x[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(option1, option2);
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
