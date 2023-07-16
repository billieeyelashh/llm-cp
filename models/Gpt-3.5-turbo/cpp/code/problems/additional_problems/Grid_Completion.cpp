
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<string> grid;
vector<vector<int>> memo;

int fillGrid(int row, int col) {
    if (row == n) {
        return 1;
    }

    if (col == n) {
        return fillGrid(row + 1, 0);
    }

    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    int ways = 0;

    if (grid[row][col] == '.') {
        // Try filling with 'A'
        grid[row][col] = 'A';
        ways += fillGrid(row, col + 1);
        ways %= MOD;
        // Try filling with 'B'
        grid[row][col] = 'B';
        ways += fillGrid(row, col + 1);
        ways %= MOD;
        // Reset the square back to empty
        grid[row][col] = '.';
    } else {
        // Move to the next square
        ways = fillGrid(row, col + 1);
    }

    return memo[row][col] = ways;
}

int main() {
    cin >> n;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    memo.assign(n, vector<int>(n, -1));

    int ways = fillGrid(0, 0);
    cout << ways << endl;

    return 0;
}
