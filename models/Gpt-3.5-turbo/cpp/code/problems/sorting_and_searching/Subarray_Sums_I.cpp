
#include <iostream>
#include <vector>

using namespace std;

int countSubarrays(vector<int>& arr, int targetSum) {
    int n = arr.size();
    int count = 0;
    int sum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        while (sum > targetSum) {
            sum -= arr[start];
            start++;
        }

        if (sum == targetSum) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countSubarrays(arr, targetSum);
    cout << result << endl;

    return 0;
}
