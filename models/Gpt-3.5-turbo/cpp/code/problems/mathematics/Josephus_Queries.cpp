
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        int m = 1;
        while (m * 2 <= n) {
            m *= 2;
        }

        int k_adjusted = (k + n - m - 1) % n;
        if (k_adjusted == 0) {
            k_adjusted = n;
        }

        cout << k_adjusted << endl;
    }

    return 0;
}
