
#include <iostream>

const int MOD = 1e9 + 7;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int inverse(int x) {
    return power(x, MOD - 2);
}

int binomialCoefficient(int n, int k) {
    int numerator = 1;
    for (int i = n; i >= n - k + 1; --i) {
        numerator = (1LL * numerator * i) % MOD;
    }
    int denominator = 1;
    for (int i = 1; i <= k; ++i) {
        denominator = (1LL * denominator * i) % MOD;
    }
    return (1LL * numerator * inverse(denominator)) % MOD;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << binomialCoefficient(n + m - 1, m) << "\n";
    return 0;
}
