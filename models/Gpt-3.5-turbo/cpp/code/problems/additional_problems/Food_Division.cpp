
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> currentFood(n);
    vector<int> requiredFood(n);

    for (int i = 0; i < n; i++) {
        cin >> currentFood[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> requiredFood[i];
    }

    int minSteps = 0;

    for (int i = 0; i < n; i++) {
        int diff = requiredFood[i] - currentFood[i];
        if (diff > 0) {
            int nextChild = (i + 1) % n;
            currentFood[i] += diff;
            currentFood[nextChild] -= diff;
            minSteps += diff;
        }
    }

    cout << minSteps << endl;

    return 0;
}
