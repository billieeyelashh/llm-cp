
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grid(2, vector<int>(n));
  int totalCoins = 0;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      totalCoins += grid[i][j];
    }
  }

  int target = totalCoins / 2;
  int moves = 0;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] > target) {
        int excess = grid[i][j] - target;
        moves += excess;
        grid[i][j] -= excess;

        if (i == 0 && j < n - 1) {
          grid[i][j + 1] += excess;
        } else if (i == 1 && j > 0) {
          grid[i][j - 1] += excess;
        }
      }
    }
  }

  cout << moves << endl;

  return 0;
}
