
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<bool> dp(1000001, false);
    dp[0] = true;

    for (int x : coins) {
        for (int i = 1000000; i >= x; --i) {
            if (dp[i - x]) {
                dp[i] = true;
            }
        }
    }

    int count = 0;
    for (bool value : dp) {
        if (value) {
            count++;
        }
    }

    cout << count << endl;
    for (int i = 0; i <= 1000000; ++i) {
        if (dp[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
