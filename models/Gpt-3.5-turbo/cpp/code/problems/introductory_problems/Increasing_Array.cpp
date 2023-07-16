
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int moves = 0;
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            moves += minVal - arr[i];
        } else {
            minVal = arr[i];
        }
    }

    cout << moves << endl;

    return 0;
}
