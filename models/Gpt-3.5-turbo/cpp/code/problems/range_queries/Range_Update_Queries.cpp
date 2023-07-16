
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;

            prefix[a] += u;
            if (b + 1 <= n) {
                prefix[b + 1] -= u;
            }
        } else {
            int k;
            cin >> k;

            long long result = prefix[1] + x[1];
            for (int j = 2; j <= k; ++j) {
                prefix[j] += prefix[j - 1];
                result += prefix[j] + x[j];
            }

            cout << result << "\n";
        }
    }

    return 0;
}
