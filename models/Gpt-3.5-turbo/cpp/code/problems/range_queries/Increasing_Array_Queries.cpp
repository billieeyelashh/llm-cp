
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    vector<long long> prefix(n + 1);

    // Read the input array
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Calculate the prefix sums
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Process the queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        // Calculate the minimum number of operations
        int operations = arr[a] - prefix[a - 1];

        // Print the result
        cout << operations << endl;
    }

    return 0;
}
