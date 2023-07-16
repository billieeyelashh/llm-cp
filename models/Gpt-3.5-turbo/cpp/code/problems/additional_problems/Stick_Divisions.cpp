
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        pq.push(d);
    }

    long long cost = 0;

    while (pq.size() > 1) {
        int stick1 = pq.top();
        pq.pop();
        int stick2 = pq.top();
        pq.pop();

        int newStick = stick1 + stick2;
        cost += newStick;

        pq.push(newStick);
    }

    cout << cost << endl;

    return 0;
}
