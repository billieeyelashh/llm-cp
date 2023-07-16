
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

    int rounds = 0;
    int maxCollected = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == maxCollected + 1) {
            maxCollected++;
        } else {
            rounds++;
        }
    }

    cout << rounds << endl;

    return 0;
}
