
#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int k) {
    if (k == n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> permutation;
    for (int i = k; i >= 1; i--) {
        permutation.push_back(i);
    }

    for (int i = k + 1; i <= n; i++) {
        permutation.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}
