
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n+1), s(n+1), k(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i-1][j];
            for (int t = 1; t <= k[i]; ++t) {
                if (j >= t * h[i]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - t * h[i]] + t * s[i]);
                }
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
