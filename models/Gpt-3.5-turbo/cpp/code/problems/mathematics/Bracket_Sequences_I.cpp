
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;

    for (int i = 2; i <= n; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            dp[i] = (dp[i] + 1LL * dp[j-2] * dp[i-j]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
