
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    int totalPermutations = factorial(s.length());
    for (int i = 0; i < 26; ++i) {
        totalPermutations = (totalPermutations * factorial(count[i])) % MOD;
    }

    std::cout << totalPermutations << std::endl;

    return 0;
}
