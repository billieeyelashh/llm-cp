
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == x) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
