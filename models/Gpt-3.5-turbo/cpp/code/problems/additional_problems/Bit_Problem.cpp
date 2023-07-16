
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    vector<int> divisors(1000001, 0);
    vector<int> bitwiseAnd(1000001, 0);
    vector<int> nonZeroAnd(1000001, 0);

    for (int i = 0; i < n; i++) {
        int x = list[i];

        // Calculate divisors
        for (int y = 1; y <= 1000000; y++) {
            if (y % x == 0) {
                divisors[x]++;
            }
        }

        // Calculate bitwiseAnd
        for (int y = 1; y <= 1000000; y++) {
            if ((x & y) == x) {
                bitwiseAnd[x]++;
            }
        }

        // Calculate nonZeroAnd
        for (int y = 1; y <= 1000000; y++) {
            if ((x & y) != 0) {
                nonZeroAnd[x]++;
            }
        }

        // Print the values
        cout << divisors[x] << " " << bitwiseAnd[x] << " " << nonZeroAnd[x] << endl;
    }

    return 0;
}
