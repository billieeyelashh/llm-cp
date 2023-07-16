
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curr_sum = 0, max_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        max_sum = max(max_sum, curr_sum);
        curr_sum = max(curr_sum, 0);
    }

    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k >> x;
        k--;

        curr_sum += x - arr[k];
        max_sum = max(max_sum, curr_sum);
        arr[k] = x;

        cout << max_sum << endl;
    }

    return 0;
}
