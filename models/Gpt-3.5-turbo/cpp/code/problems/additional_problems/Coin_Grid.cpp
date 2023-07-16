
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int, int>> moves;

    // Iterate through each row
    for (int i = 0; i < n; i++) {
        bool hasCoin = false;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'o') {
                hasCoin = true;
                break;
            }
        }
        if (hasCoin) {
            moves.push_back({1, i + 1}); // Remove row i+1
        }
    }

    // Iterate through each column
    for (int j = 0; j < n; j++) {
        bool hasCoin = false;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'o') {
                hasCoin = true;
                break;
            }
        }
        if (hasCoin) {
            moves.push_back({2, j + 1}); // Remove column j+1
        }
    }

    cout << moves.size() << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
