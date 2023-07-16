
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;

    return 0;
}
