
#include <iostream>

int powerMod(int a, int b, int mod) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << powerMod(a, b, 1000000007) << "\n";
    }
    return 0;
}
