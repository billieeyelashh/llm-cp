
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    long long result = power(2, n);
    cout << result << endl;
    return 0;
}
