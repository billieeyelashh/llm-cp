
#include <iostream>

using namespace std;

int countOneBits(long long n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;

    long long totalBits = 0;
    for (long long i = 1; i <= n; i++) {
        totalBits += countOneBits(i);
    }

    cout << totalBits << endl;

    return 0;
}
