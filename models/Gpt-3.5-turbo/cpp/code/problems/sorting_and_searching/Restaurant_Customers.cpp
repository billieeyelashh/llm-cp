
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arrivals[n], leavings[n];
    for (int i = 0; i < n; i++) {
        cin >> arrivals[i] >> leavings[i];
    }

    sort(arrivals, arrivals + n);
    sort(leavings, leavings + n);

    int current_count = 0, max_count = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arrivals[i] <= leavings[j]) {
            current_count++;
            i++;
        } else {
            current_count--;
            j++;
        }
        max_count = max(max_count, current_count);
    }

    cout << max_count << endl;

    return 0;
}
