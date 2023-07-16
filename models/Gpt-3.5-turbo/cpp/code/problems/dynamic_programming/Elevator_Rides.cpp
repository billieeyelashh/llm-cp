
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int rides = 0;
    int current_weight = 0;
    int i = 0;

    while (i < n) {
        if (current_weight + weights[i] <= x) {
            current_weight += weights[i];
            i++;
        } else {
            rides++;
            current_weight = 0;
        }
    }

    if (current_weight > 0) {
        rides++;
    }

    cout << rides << endl;

    return 0;
}
