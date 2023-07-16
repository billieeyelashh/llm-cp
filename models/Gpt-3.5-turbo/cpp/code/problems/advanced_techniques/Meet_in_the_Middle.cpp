
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= t[i - 1]) {
                dp[i][j] += dp[i - 1][j - t[i - 1]];
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
