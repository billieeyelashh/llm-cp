
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int currSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        currSum += arr[right];

        if (right - left + 1 > b) {
            currSum -= arr[left];
            left++;
        }

        if (right - left + 1 >= a) {
            maxSum = max(maxSum, currSum);
        }
    }

    cout << maxSum << endl;

    return 0;
}
