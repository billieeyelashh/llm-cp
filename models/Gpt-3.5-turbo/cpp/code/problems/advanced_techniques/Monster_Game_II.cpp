
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<long long> dp(n+1);
    dp[1] = static_cast<long long>(s[0]) * f[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1] + static_cast<long long>(s[i-1]) * f[i-1], dp[i-1]);
    }

    cout << dp[n] << endl;

    return 0;
}
