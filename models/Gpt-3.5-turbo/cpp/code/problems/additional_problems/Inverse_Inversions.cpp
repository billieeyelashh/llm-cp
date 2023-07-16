
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Create a permutation of numbers in increasing order
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    // Use the remaining inversions to create desired inversions
    for (int i = n - 2; i >= 0 && k > 0; i--) {
        swap(permutation[i], permutation[i + 1]);
        k--;
    }

    // Print the permutation
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
