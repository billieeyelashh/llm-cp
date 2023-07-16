
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create a window of size k
    vector<int> window(arr.begin(), arr.begin() + k);
    sort(window.begin(), window.end());

    // Print the median of the first window
    cout << window[k/2] << " ";

    // Slide the window and update the sorted window
    for (int i = k; i < n; i++) {
        // Remove the first element from the window
        window.erase(lower_bound(window.begin(), window.end(), arr[i-k]));

        // Insert the new element into the window
        window.insert(upper_bound(window.begin(), window.end(), arr[i]), arr[i]);

        // Print the median of the current window
        cout << window[k/2] << " ";
    }

    return 0;
}
