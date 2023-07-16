
#include <iostream>
#include <vector>

using namespace std;

bool solveGrid(int n, int m) {
    if (n * m % 3 != 0) {
        return false;
    }

    vector<vector<char>> grid(n, vector<char>(m));

    // Fill the first row with 'A'
    for (int j = 0; j < m; j++) {
        grid[0][j] = 'A';
    }

    // Fill the first column with 'B'
    for (int i = 0; i < n; i++) {
        grid[i][0] = 'B';
    }

    // Fill the remaining cells
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (i % 2 == 0 && j % 2 == 1) {
                grid[i][j] = grid[i][j - 1];
            } else if (i % 2 == 1 && j % 2 == 0) {
                grid[i][j] = grid[i - 1][j];
            } else {
                grid[i][j] = grid[i - 1][j - 1];
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (solveGrid(n, m)) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
