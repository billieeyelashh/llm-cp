
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = INT_MAX;
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + abs(c[i] - c[l + 1]));
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
