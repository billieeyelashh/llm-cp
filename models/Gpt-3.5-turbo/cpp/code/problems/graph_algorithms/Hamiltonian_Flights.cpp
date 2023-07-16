
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> flights;
vector<bool> visited;

int countRoutes(int city) {
    if (city == n) {
        // Reached Lehmälä, all cities visited once
        return 1;
    }

    int routes = 0;
    visited[city] = true;

    for (int i = 0; i < m; i++) {
        int from = flights[i][0];
        int to = flights[i][1];

        if (from == city && !visited[to]) {
            routes += countRoutes(to);
            routes %= MOD;
        }
    }

    visited[city] = false; // Reset visited for backtracking
    return routes;
}

int main() {
    cin >> n >> m;

    flights.resize(m, vector<int>(2));
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1];
    }

    int routes = countRoutes(1); // Start from Syrjälä (city 1)
    cout << routes << endl;

    return 0;
}
