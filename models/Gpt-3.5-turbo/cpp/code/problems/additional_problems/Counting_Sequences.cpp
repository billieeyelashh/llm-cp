
#include <iostream>

const int MOD = 1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;

    // Calculate k!
    long long factorial = 1;
    for (int i = 1; i <= k; i++) {
        factorial = (factorial * i) % MOD;
    }

    // Calculate (n - k)^(n - k)
    long long repetitions = 1;
    for (int i = 1; i <= n - k; i++) {
        repetitions = (repetitions * (n - k)) % MOD;
    }

    // Multiply k! and (n - k)^(n - k)
    long long result = (factorial * repetitions) % MOD;

    std::cout << result << std::endl;

    return 0;
}
