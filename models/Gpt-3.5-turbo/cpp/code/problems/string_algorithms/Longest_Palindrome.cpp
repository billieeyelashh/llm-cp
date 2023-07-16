
#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Single characters are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    int maxLen = 1, start = 0;

    // Check for palindromes of length 2 or more
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int end = i + length - 1;

            if (s[i] == s[end]) {
                // If inner substring is palindrome, then current substring is also palindrome
                if (length == 2 || dp[i + 1][end - 1]) {
                    dp[i][end] = true;

                    if (length > maxLen) {
                        maxLen = length;
                        start = i;
                    }
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}
