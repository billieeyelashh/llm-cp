
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    unordered_map<int, vector<int>> mp;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int remaining = x - (arr[i] + arr[j]);
            if (mp.count(remaining)) {
                for (int k : mp[remaining]) {
                    if (k != i + 1 && k != j + 1) {
                        cout << i + 1 << " " << j + 1 << " " << k << " " << mp[remaining][0] << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
