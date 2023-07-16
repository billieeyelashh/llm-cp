
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the prefix xor array
    vector<int> prefixXor(n);
    prefixXor[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixXor[i] = prefixXor[i-1] ^ arr[i];
    }

    // Process the queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        // If the range starts from the beginning of the array, the xor sum is the prefix xor value at index b
        if (a == 1) {
            cout << prefixXor[b-1] << endl;
        }
        // Otherwise, the xor sum is the xor of prefix xor values at index a-2 and b-1
        else {
            cout << (prefixXor[a-2] ^ prefixXor[b-1]) << endl;
        }
    }

    return 0;
}
