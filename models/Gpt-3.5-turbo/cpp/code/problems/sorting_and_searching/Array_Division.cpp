
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& arr, int maxSum, int k) {
    int cnt = 1;
    int currSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxSum) {
            return false;
        }
        if (currSum + arr[i] > maxSum) {
            cnt++;
            currSum = arr[i];
        } else {
            currSum += arr[i];
        }
    }
    return cnt <= k;
}

int solve(vector<int>& arr, int k) {
    int left = 1;
    int right = 0;
    for (int i = 0; i < arr.size(); i++) {
        right += arr[i];
    }

    int ans = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(arr, mid, k)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = solve(arr, k);
    cout << result << endl;

    return 0;
}
