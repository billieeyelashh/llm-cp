
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].first >> customers[i].second;
    }

    sort(customers.begin(), customers.end());

    priority_queue<int, vector<int>, greater<int>> departures;
    vector<int> roomNumber(n);

    int room = 1;
    for (int i = 0; i < n; i++) {
        if (!departures.empty() && departures.top() <= customers[i].first) {
            departures.pop();
        } else {
            room++;
        }
        departures.push(customers[i].second);
        roomNumber[i] = room;
    }

    cout << room << endl;
    for (int i = 0; i < n; i++) {
        cout << roomNumber[i] << " ";
    }

    return 0;
}
