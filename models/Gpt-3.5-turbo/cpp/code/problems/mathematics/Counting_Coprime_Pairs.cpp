
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000; // maximum limit for x_i

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // Precompute primes up to MAX_N using Sieve of Eratosthenes
    vector<bool> isPrime(MAX_N + 1, true);
    vector<int> primes;
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
            for (int i = p * p; i <= MAX_N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int gcd = 1;
            for (int prime : primes) {
                if (prime > x[i] || prime > x[j]) {
                    break;
                }
                if (x[i] % prime == 0 && x[j] % prime == 0) {
                    gcd = prime;
                    break;
                }
            }
            if (gcd == 1) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
