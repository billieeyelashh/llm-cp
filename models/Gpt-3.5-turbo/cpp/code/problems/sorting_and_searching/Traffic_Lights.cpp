
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    // Create an interval tree using a set of pairs (start, end)
    set<pair<int, int>> intervals;

    // Insert the initial interval representing the entire street
    intervals.insert({0, x});

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        // Find the interval containing p
        auto it = intervals.upper_bound({p, -1});
        it--;

        // Split the interval into two intervals
        int start = it->first;
        int end = it->second;
        intervals.erase(it);
        if (start < p) {
            intervals.insert({start, p - 1});
        }
        if (p < end) {
            intervals.insert({p + 1, end});
        }

        // Calculate the longest passage without traffic lights
        int max_length = 0;
        for (auto interval : intervals) {
            int length = interval.second - interval.first + 1;
            max_length = max(max_length, length);
        }

        // Print the longest passage length
        cout << max_length << " ";
    }

    return 0;
}
