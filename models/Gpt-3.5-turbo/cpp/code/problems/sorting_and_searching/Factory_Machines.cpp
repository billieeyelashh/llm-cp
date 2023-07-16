
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    // Binary search range
    long long minTime = 1, maxTime = *max_element(machines.begin(), machines.end()) * 1LL * t;
    long long result = maxTime;

    while (minTime <= maxTime) {
        long long midTime = (minTime + maxTime) / 2;

        // Count the total number of products made within midTime
        long long totalProducts = 0;
        for (int machine : machines) {
            totalProducts += midTime / machine;
        }

        if (totalProducts >= t) {
            result = midTime;
            maxTime = midTime - 1;
        } else {
            minTime = midTime + 1;
        }
    }

    cout << result << endl;

    return 0;
}
