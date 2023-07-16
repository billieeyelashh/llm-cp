
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        long long total_ways = 1LL * k * k * (k * k - 1);
        long long attack_ways = 2LL * (k - 2) * (k - 1) + 4LL * (k - 1) * (k - 2);
        long long non_attack_ways = total_ways - attack_ways;

        cout << non_attack_ways << " ";
    }

    return 0;
}
