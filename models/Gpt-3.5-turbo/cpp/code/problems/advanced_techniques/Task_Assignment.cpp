
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int hungarian(const vector<vector<int>>& cost_matrix) {
    int n = cost_matrix.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;

            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    int cur = cost_matrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }

            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    return -v[0];
}

void print_assignment(const vector<vector<int>>& cost_matrix) {
    int n = cost_matrix.size();
    vector<int> assignment(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (assignment[j] == 0 || cost_matrix[i - 1][j - 1] - u[i] - v[j] < cost_matrix[assignment[j] - 1][j - 1] - u[assignment[j]] - v[j]) {
                assignment[j] = i;
            }
        }
    }

    cout << hungarian(cost_matrix) << endl;
    for (int j = 1; j <= n; ++j) {
        cout << assignment[j] << " " << j << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cost_matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost_matrix[i][j];
        }
    }

    print_assignment(cost_matrix);

    return 0;
}
