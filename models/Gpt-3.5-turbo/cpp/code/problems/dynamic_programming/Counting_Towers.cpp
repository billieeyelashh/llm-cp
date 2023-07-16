
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<int> memo;

int countTowers(int n) {
    if (n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int ans = (countTowers(n-1) + 2 * countTowers(n-2)) % MOD;
    memo[n] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;

    memo.resize(1000001, -1);
    memo[1] = 1;

    while (t--) {
        int n;
        cin >> n;
        cout << countTowers(n) << endl;
    }

    return 0;
}
