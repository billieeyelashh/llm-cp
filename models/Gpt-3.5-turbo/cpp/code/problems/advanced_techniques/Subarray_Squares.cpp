
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    // Base case: j = 1
    for (int i = 1; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + arr[i];
    }

    for (int j = 2; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = 1e18;  // Initialize with a large value

            long long sum = 0;
            for (int p = i; p >= 1; p--) {
                sum += arr[p];
                dp[i][j] = min(dp[i][j], dp[p - 1][j - 1] + sum * sum);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
