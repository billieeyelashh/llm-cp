
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flights; // adjacency list representation of the flight connections
vector<bool> visited; // to keep track of visited cities
vector<int> route; // to store the current round trip

bool dfs(int city) {
    visited[city] = true;
    route.push_back(city);

    // check if we have found a round trip
    if (route.size() > 2 && route[0] == route.back()) {
        return true;
    }

    for (int nextCity : flights[city]) {
        if (!visited[nextCity]) {
            if (dfs(nextCity)) {
                return true;
            }
        }
    }

    // backtrack if no round trip found
    visited[city] = false;
    route.pop_back();

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    flights.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        flights[a].push_back(b);
    }

    bool foundRoundTrip = false;
    for (int city = 1; city <= n; ++city) {
        if (!visited[city] && dfs(city)) {
            foundRoundTrip = true;
            break;
        }
    }

    if (foundRoundTrip) {
        cout << route.size() << endl;
        for (int city : route) {
            cout << city << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
