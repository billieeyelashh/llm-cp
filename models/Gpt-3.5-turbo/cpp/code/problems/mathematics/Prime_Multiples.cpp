
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    long long ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        long long prod = 1;
        int bits = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                prod *= primes[i];
                bits++;
            }
        }

        long long cnt = n / prod;
        if (bits % 2 == 1) {
            ans += cnt;
        } else {
            ans -= cnt;
        }
    }

    cout << ans << endl;

    return 0;
}
