
#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = longestIncreasingSubsequence(arr);
    std::cout << result << std::endl;

    return 0;
}
