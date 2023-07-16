
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            grid[i][j] = row[j-1] - '0';
        }
    }

    int beautiful_subgrids = 0;

    for (int i = 3; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                beautiful_subgrids += dp[i][j];
            }
        }
    }

    cout << beautiful_subgrids << endl;

    return 0;
}
