
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    int k;
    cin >> k;
    
    vector<string> words(k);
    for (int i = 0; i < k; i++) {
        cin >> words[i];
    }
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int length = words[j].length();
            if (i >= length && s.substr(i - length, length) == words[j]) {
                dp[i] = (dp[i] + dp[i - length]) % MOD;
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
