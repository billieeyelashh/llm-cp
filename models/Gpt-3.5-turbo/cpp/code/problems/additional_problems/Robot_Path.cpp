
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    int totalDistance = 0;
    int x = 0, y = 0;
    set<pair<int, int>> visitedPositions;
    visitedPositions.insert({x, y});

    for (int i = 0; i < n; i++) {
        char d;
        int distance;
        cin >> d >> distance;

        if (d == 'U') {
            y += distance;
        } else if (d == 'D') {
            y -= distance;
        } else if (d == 'L') {
            x -= distance;
        } else if (d == 'R') {
            x += distance;
        }

        if (visitedPositions.count({x, y}) > 0) {
            break;
        }

        visitedPositions.insert({x, y});
        totalDistance += distance;
    }

    cout << totalDistance << endl;

    return 0;
}
