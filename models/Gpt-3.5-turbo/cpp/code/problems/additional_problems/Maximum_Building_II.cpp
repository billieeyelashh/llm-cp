
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<string> forest(n);
    for (int i = 0; i < n; i++) {
        cin >> forest[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (forest[i-1][j-1] == '.') {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
