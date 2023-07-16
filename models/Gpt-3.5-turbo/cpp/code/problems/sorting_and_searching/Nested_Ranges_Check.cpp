
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    int start, end;
};

bool compareRanges(const Range& r1, const Range& r2) {
    if (r1.start == r2.start) {
        return r1.end > r2.end;
    }
    return r1.start < r2.start;
}

int main() {
    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].start >> ranges[i].end;
    }
    
    // Sort the ranges based on their starting points
    sort(ranges.begin(), ranges.end(), compareRanges);
    
    vector<int> contains(n, 0); // stores if a range is contained by any other range
    vector<int> contained(n, 0); // stores if a range is contained by some other range
    
    int max_ending = ranges[0].end;
    int min_starting = ranges[0].start;
    
    for (int i = 1; i < n; ++i) {
        // Check if the current range is contained by any previous range
        if (ranges[i].start <= max_ending) {
            contains[i] = 1;
        }
        
        // Update the maximum ending point
        max_ending = max(max_ending, ranges[i].end);
        
        // Check if the current range contains some previous range
        if (ranges[i].end < min_starting) {
            contained[i] = 1;
        }
        
        // Update the minimum starting point
        min_starting = min(min_starting, ranges[i].start);
    }
    
    // Print the results
    for (int i = 0; i < n; ++i) {
        cout << contains[i] << ' ';
    }
    cout << '\n';
    
    for (int i = 0; i < n; ++i) {
        cout << contained[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
