
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cubes(n);
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int cube = cubes[i];

        // Find the first tower where the cube can be placed
        auto it = lower_bound(towers.begin(), towers.end(), cube);

        // If no such tower exists, start a new tower
        if (it == towers.end()) {
            towers.push_back(cube);
        } 
        // Otherwise, update the tower with the smallest possible cube size
        else {
            *it = cube;
        }
    }

    cout << towers.size() << endl;

    return 0;
}
