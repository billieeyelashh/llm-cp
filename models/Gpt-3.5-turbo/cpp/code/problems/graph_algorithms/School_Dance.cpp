
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> boy_available(n + 1, true); // to keep track of available boys
    vector<bool> girl_available(m + 1, true); // to keep track of available girls

    vector<pair<int, int>> dance_pairs; // to store the dance pairs

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        // If both the boy and girl are available, form a pair
        if (boy_available[a] && girl_available[b]) {
            dance_pairs.push_back({a, b});
            boy_available[a] = false;
            girl_available[b] = false;
        }
    }

    int r = dance_pairs.size(); // the maximum number of dance pairs

    cout << r << endl;
    for (auto pair : dance_pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
