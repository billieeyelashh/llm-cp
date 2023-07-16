
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

// Function to compute the sum of divisors for each prime number up to n
vector<long long> computeSumOfDivisors(int n) {
    vector<long long> sumOfDivisors(n + 1, 1);
    
    for (int i = 2; i <= n; i++) {
        if (sumOfDivisors[i] == 1) { // i is a prime number
            for (int j = i; j <= n; j += i) {
                int p = j, power = 0;
                while (p % i == 0) {
                    p /= i;
                    power++;
                }
                sumOfDivisors[j] *= (power + 1);
                sumOfDivisors[j] %= MOD;
            }
        }
    }
    
    return sumOfDivisors;
}

int main() {
    int n;
    cin >> n;

    vector<long long> sumOfDivisors = computeSumOfDivisors(n);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sumOfDivisors[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
