
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            // Exclude book i
            dp[i][j] = dp[i - 1][j];

            // Include book i if price[i-1] is less than or equal to j
            if (price[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - price[i - 1]]);
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
