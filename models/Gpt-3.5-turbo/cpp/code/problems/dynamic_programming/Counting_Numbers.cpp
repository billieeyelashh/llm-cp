
#include <iostream>
#include <vector>

using namespace std;

long long dp(int n, int s, int t, vector<vector<vector<long long>>>& memo) {
    if (n == 0) return 1;
    if (memo[n][s][t] != -1) return memo[n][s][t];

    long long count = 0;
    for (int d = 0; d <= 9; d++) {
        if (d != s && d != t) {
            count += dp(n - 1, t, d, memo);
        }
    }

    return memo[n][s][t] = count;
}

int main() {
    long long a, b;
    cin >> a >> b;

    int n = to_string(b).size();

    vector<vector<vector<long long>>> memo(n + 1, vector<vector<long long>>(10, vector<long long>(10, -1)));

    long long answer = 0;
    for (int s = 0; s <= 9; s++) {
        for (int t = 0; t <= 9; t++) {
            answer += dp(n, s, t, memo);
        }
    }

    if (a > 0) {
        n = to_string(a - 1).size();
        memo.assign(n + 1, vector<vector<long long>>(10, vector<long long>(10, -1)));

        for (int s = 0; s <= 9; s++) {
            for (int t = 0; t <= 9; t++) {
                answer -= dp(n, s, t, memo);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
