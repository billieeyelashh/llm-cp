
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int powMod(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int countNecklaces(int n, int m) {
    int total = 0;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            int fixedPoints = powMod(m, gcd(n, k));
            total = (total + fixedPoints) % MOD;
        }
    }
    total = (1LL * total * powMod(n, MOD - 2)) % MOD; // Modular inverse of n
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    int result = countNecklaces(n, m);
    cout << result << endl;
    return 0;
}
