
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    sum += p[i];
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum / 2; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= p[i - 1]) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - p[i - 1]];
      }
    }
  }

  int minDiff = sum;
  for (int j = 0; j <= sum / 2; j++) {
    if (dp[n][j]) {
      minDiff = min(minDiff, sum - 2 * j);
    }
  }

  cout << minDiff << endl;

  return 0;
}
