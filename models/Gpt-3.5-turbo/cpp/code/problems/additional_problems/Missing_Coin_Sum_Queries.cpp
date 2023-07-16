
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + coins[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        long long sum = prefixSum[b] - prefixSum[a - 1];
        
        int ans = 1;
        for (int i = a - 1; i <= b - 1; ++i) {
            if (coins[i] > ans) {
                break;
            }
            ans += coins[i];
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
