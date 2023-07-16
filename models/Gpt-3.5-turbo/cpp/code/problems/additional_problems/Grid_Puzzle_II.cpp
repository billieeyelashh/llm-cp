
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 50;

int n;
int rows[MAXN], cols[MAXN];
int grid[MAXN][MAXN];
int chosenRows[MAXN], chosenCols[MAXN];
int maxCoins = -1;

void backtrack(int row, int col, int coins) {
    if (row == n) {
        // Reached the end, update the maximum number of coins
        maxCoins = max(maxCoins, coins);
        return;
    }

    // If we have already chosen enough squares in this row and column, move to the next one
    if (chosenRows[row] == rows[row]) {
        backtrack(row + 1, col, coins);
        return;
    }
    if (chosenCols[col] == cols[col]) {
        backtrack(row, col + 1, coins);
        return;
    }

    // Try choosing a square in the current row and column
    chosenRows[row]++;
    chosenCols[col]++;
    backtrack(row, col, coins + grid[row][col]);
    chosenRows[row]--;
    chosenCols[col]--;

    // Move to the next square
    backtrack(row, col + 1, coins);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cols[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Start backtracking from the top-left square
    backtrack(0, 0, 0);

    if (maxCoins == -1) {
        cout << -1 << endl;
    } else {
        cout << maxCoins << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chosenRows[i] && chosenCols[j]) {
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
