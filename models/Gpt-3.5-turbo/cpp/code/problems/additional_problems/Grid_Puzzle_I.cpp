
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> row_constraints(n), col_constraints(n);
    for (int i = 0; i < n; ++i) {
        cin >> row_constraints[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> col_constraints[i];
    }

    vector<vector<char>> grid(n, vector<char>(n, '.'));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row_constraints[i] > 0 && col_constraints[j] > 0) {
                grid[i][j] = 'X';
                row_constraints[i]--;
                col_constraints[j]--;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (row_constraints[i] > 0 || col_constraints[i] > 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
