
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arrays(1, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> arrays[0][i];
    }

    vector<vector<int>> prefixSums(1, vector<int>(n + 1));
    for (int k = 0; k < 1; ++k) {
        for (int i = 1; i <= n; ++i) {
            prefixSums[k][i] = prefixSums[k][i - 1] + arrays[k][i - 1];
        }
    }

    while (q--) {
        int type, k, a, b;
        cin >> type >> k;

        if (type == 1) {
            int x;
            cin >> a >> x;
            --a;
            arrays[k - 1][a] = x;
            prefixSums[k - 1][a + 1] = prefixSums[k - 1][a] + x;
        } else if (type == 2) {
            cin >> a >> b;
            --a, --b;
            int sum = prefixSums[k - 1][b + 1] - prefixSums[k - 1][a];
            cout << sum << endl;
        } else if (type == 3) {
            arrays.push_back(arrays[k - 1]);
            prefixSums.push_back(prefixSums[k - 1]);
        }
    }

    return 0;
}
