
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + x[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int sum = prefix[b] - prefix[a - 1];
        cout << sum << endl;
    }

    return 0;
}
