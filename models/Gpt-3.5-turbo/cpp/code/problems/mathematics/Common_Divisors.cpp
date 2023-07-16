
#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int maxGcd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int currentGcd = gcd(arr[i], arr[j]);
            maxGcd = std::max(maxGcd, currentGcd);
        }
    }

    std::cout << maxGcd << std::endl;

    return 0;
}
