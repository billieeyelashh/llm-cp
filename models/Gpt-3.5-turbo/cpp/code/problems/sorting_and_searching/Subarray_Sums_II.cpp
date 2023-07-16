
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    int left = 0, right = 0;
    int sum = 0;

    while (right < n) {
        sum += a[right];

        while (sum > x && left <= right) {
            sum -= a[left];
            left++;
        }

        if (sum == x) {
            count++;
        }

        right++;
    }

    cout << count << endl;

    return 0;
}
