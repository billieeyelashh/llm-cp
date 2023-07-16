
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    int smallestSum = 1;
    for (int i = 0; i < n && coins[i] <= smallestSum; ++i) {
        smallestSum += coins[i];
    }

    cout << smallestSum << endl;

    return 0;
}
