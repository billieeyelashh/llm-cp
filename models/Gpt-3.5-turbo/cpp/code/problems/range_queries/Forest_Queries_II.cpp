
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix_sum(n + 1, vector<int>(n + 1, 0));

    // Read the forest map
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            if (row[j - 1] == '*') {
                forest[i][j] = 1;
            }
        }
    }

    // Calculate prefix sum
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = forest[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    // Process queries
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int y, x;
            cin >> y >> x;
            forest[y][x] = 1 - forest[y][x]; // Toggle the state of the square
            for (int i = y; i <= n; i++) {
                for (int j = x; j <= n; j++) {
                    prefix_sum[i][j] += (forest[y][x] == 1) ? 1 : -1; // Update the prefix sum accordingly
                }
            }
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            int number_of_trees = prefix_sum[y2][x2] - prefix_sum[y2][x1 - 1] - prefix_sum[y1 - 1][x2] + prefix_sum[y1 - 1][x1 - 1];
            cout << number_of_trees << endl;
        }
    }

    return 0;
}
