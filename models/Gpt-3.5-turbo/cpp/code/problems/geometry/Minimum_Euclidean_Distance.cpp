
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int minDistance = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
            minDistance = min(minDistance, distance);
        }
    }

    cout << minDistance << endl;

    return 0;
}
