#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const long long INF = 1e18;
long long dp[1<<MAXN], weights[MAXN], total;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> weights[i];
        total += weights[i];
    }

    sort(weights, weights+n);

    for(int i=0; i<(1<<n); i++) dp[i] = INF;
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<(1<<i); j++) {
            dp[j|(1<<i)] = min(dp[j|(1<<i)], max(dp[j] + weights[i], total - dp[j] - weights[i]));
        }
    }

    cout << dp[(1<<n) - 1] << "\n";

    return 0;
}