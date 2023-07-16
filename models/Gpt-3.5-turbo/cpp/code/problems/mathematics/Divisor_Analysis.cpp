
#include <iostream>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    long long int number = 1;
    long long int sum = 1;
    long long int product = 1;

    for (int i = 0; i < n; i++) {
        int x, k;
        std::cin >> x >> k;

        long long int term = 1;
        long long int power = 1;

        for (int j = 0; j < k; j++) {
            power = (power * x) % MOD;
            term = (term + power) % MOD;
        }

        number = (number * (k + 1)) % MOD;
        sum = (sum * term) % MOD;
        product = (product * power) % MOD;
    }

    std::cout << number << " " << sum << " " << product << std::endl;

    return 0;
}
