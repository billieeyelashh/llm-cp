
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    vector<vector<int>> tunnels(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        tunnels[a-1].push_back(b-1);
    }
    
    vector<int> dp(n, -INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < tunnels[i].size(); ++j) {
            int next_room = tunnels[i][j];
            dp[next_room] = max(dp[next_room], dp[i] + coins[next_room]);
        }
    }
    
    int max_coins = *max_element(dp.begin(), dp.end());
    cout << max_coins << endl;
    
    return 0;
}
