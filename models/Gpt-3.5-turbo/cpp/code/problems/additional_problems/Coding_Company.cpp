
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int max_skill = t[i - 1], min_skill = t[i - 1];
            for (int k = i - 1; k >= 0; k--) {
                max_skill = max(max_skill, t[k]);
                min_skill = min(min_skill, t[k]);

                if (x - (max_skill - min_skill) < 0) {
                    break;
                }

                dp[i][j] = (dp[i][j] + dp[k][j - 1]) % MOD;
            }
        }
    }

    int answer = 0;
    for (int j = 1; j <= n; j++) {
        answer = (answer + dp[n][j]) % MOD;
    }

    cout << answer << endl;

    return 0;
}
