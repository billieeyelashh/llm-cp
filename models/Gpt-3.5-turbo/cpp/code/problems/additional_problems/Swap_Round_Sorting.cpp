
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }

    int rounds = 0;
    for (int i = 0; i < n; ++i) {
        while (permutation[i] != i + 1) {
            swap(permutation[i], permutation[permutation[i] - 1]);
            rounds++;
        }
    }

    cout << rounds << endl;

    int start = 0;
    for (int i = 0; i < rounds; ++i) {
        int swaps = 0;
        for (int j = start; j < n; ++j) {
            if (permutation[j] != j + 1) {
                cout << swaps + 1 << endl;
                cout << start + 1 << " " << j + 1 << endl;
                start = j + 1;
                break;
            }
            swaps++;
        }
    }

    return 0;
}
