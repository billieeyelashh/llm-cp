
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(2));
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    int requiredRoads = 0;
    cout << n - 1 << endl;

    visited[1] = true;

    for (int i = 0; i < m; i++) {
        if (visited[roads[i][0]] && !visited[roads[i][1]]) {
            visited[roads[i][1]] = true;
            requiredRoads++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (visited[roads[i][0]] && !visited[roads[i][1]]) {
            cout << roads[i][0] << " " << roads[i][1] << endl;
        }
    }

    return 0;
}
