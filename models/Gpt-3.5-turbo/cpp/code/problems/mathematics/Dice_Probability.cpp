
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    double dp[101][601] = {0};
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 * i; j++) {
            for (int k = 1; k <= min(j, 6); k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
            dp[i][j] /= 6;
        }
    }

    double probability = 0;
    for (int j = a; j <= b; j++) {
        probability += dp[n][j];
    }

    cout << fixed << setprecision(6) << probability << endl;

    return 0;
}
