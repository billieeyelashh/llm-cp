
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    long long totalCost = 0;

    while (pq.size() > 1) {
        int smallest = pq.top();
        pq.pop();
        int secondSmallest = pq.top();
        pq.pop();

        totalCost += smallest + secondSmallest;

        pq.push(smallest + secondSmallest);
    }

    cout << totalCost << endl;

    return 0;
}
