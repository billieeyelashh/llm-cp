
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    unordered_map<int, int> mp;
    
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        
        if (mp.count(x - a)) {
            cout << mp[x - a] << " " << i << endl;
            return 0;
        }
        
        mp[a] = i;
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
