
#include <iostream>
#include <vector>

const int MOD = 1000000007;

std::vector<int> memo;

int derangements(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int derange = (n - 1) * (derangements(n - 1) + derangements(n - 2)) % MOD;
    memo[n] = derange;
    return derange;
}

int main() {
    int n;
    std::cin >> n;

    memo.resize(n + 1, -1);
    memo[2] = 1;

    std::cout << derangements(n) << std::endl;

    return 0;
}
