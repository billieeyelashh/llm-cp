
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end()); // Step 2

    int total_time = 0;
    int max_time = 0;

    for (int i = 0; i < n; i++) { // Step 4
        total_time += times[i]; // Step 4a
        max_time = max(max_time, total_time); // Step 4b
    }

    cout << max_time << endl; // Step 5

    return 0;
}
