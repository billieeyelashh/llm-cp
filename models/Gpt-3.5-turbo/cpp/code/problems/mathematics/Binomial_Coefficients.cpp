
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAX = 1000000;

vector<int> factorial(MAX + 1, 1);

int power(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * 1LL * base) % MOD;
        }
        base = (base * 1LL * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute_factorials() {
    for (int i = 2; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * 1LL * i) % MOD;
    }
}

int inverse_modulo(int num) {
    return power(num, MOD - 2);
}

int binomial_coefficient(int a, int b) {
    int numerator = factorial[a];
    int denominator = (factorial[b] * 1LL * factorial[a - b]) % MOD;
    int inverse_denominator = inverse_modulo(denominator);
    return (numerator * 1LL * inverse_denominator) % MOD;
}

int main() {
    precompute_factorials();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << binomial_coefficient(a, b) << endl;
    }

    return 0;
}
