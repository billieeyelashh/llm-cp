
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> s(n+1);
    vector<int> f(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    
    vector<long long> dp(n+1);
    dp[n] = static_cast<long long>(s[n]) * x;
    
    for (int i = n-1; i >= 1; i--) {
        dp[i] = min(dp[i+1], static_cast<long long>(s[i]) * f[i] + dp[i+1]);
    }
    
    cout << dp[1] << endl;
    
    return 0;
}
