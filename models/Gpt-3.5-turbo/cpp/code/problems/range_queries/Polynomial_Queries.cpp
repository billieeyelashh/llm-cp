
#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Tree (BIT) data structure
struct BIT {
    vector<int> bit;

    BIT(int n) {
        bit.resize(n + 1);
    }

    // Update the value at index i by adding val
    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += i & (-i);
        }
    }

    // Calculate the prefix sum up to index i
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }

    // Calculate the sum in the range [a, b]
    int rangeSum(int a, int b) {
        return query(b) - query(a - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    BIT bit(n);

    // Initialize the BIT with the initial contents of the array
    for (int i = 1; i <= n; i++) {
        bit.update(i, t[i - 1]);
    }

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            // Update the values in the range [a, b]
            for (int i = a; i <= b; i++) {
                bit.update(i, i - a + 1);
            }
        } else {
            // Calculate and print the sum in the range [a, b]
            cout << bit.rangeSum(a, b) << endl;
        }
    }

    return 0;
}
