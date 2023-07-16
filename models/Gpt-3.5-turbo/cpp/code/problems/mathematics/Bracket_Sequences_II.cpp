
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countValidSequences(int n, string prefix) {
    int k = prefix.length();
    vector<int> dp(n + 1, 0);
    
    if (k % 2 != 0) {
        return 0; // Prefix has imbalance
    }
    
    dp[0] = 1;
    int prefixBalance = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            prefixBalance += (prefix[i - 1] == '(') ? 1 : -1;
        }
        else {
            prefixBalance += (prefix[i - 1] == '(') ? 1 : -1;
            prefixBalance -= (prefix[i - k - 1] == '(') ? 1 : -1;
        }
        
        if (prefixBalance < 0) {
            continue; // Prefix has imbalance
        }
        
        for (int j = 1; j <= min(i, k); j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    string prefix;
    cin >> n >> prefix;
    
    int ans = countValidSequences(n, prefix);
    cout << ans << endl;
    
    return 0;
}
