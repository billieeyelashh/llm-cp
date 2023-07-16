
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dp[b] = (dp[b] + dp[a]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}
