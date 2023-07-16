
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n+1, vector<int>(n+1, 0));

    // Read forest grid
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            forest[i][j] = (row[j-1] == '*') ? 1 : 0;
        }
    }

    // Calculate prefix sum grid
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            forest[i][j] += forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
        }
    }

    // Process queries
    for (int query = 0; query < q; query++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int treesInsideRectangle = forest[y2][x2] - forest[y2][x1-1] - forest[y1-1][x2] + forest[y1-1][x1-1];
        cout << treesInsideRectangle << endl;
    }

    return 0;
}
