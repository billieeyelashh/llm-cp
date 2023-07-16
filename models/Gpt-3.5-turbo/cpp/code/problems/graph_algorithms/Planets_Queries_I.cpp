
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> destinations(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> destinations[i];
    }

    vector<bool> visited(n + 1, false);
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;

        int current_planet = x;
        int teleport_count = 0;
        while (!visited[current_planet]) {
            visited[current_planet] = true;
            current_planet = destinations[current_planet];
            ++teleport_count;
        }

        int cycle_length = teleport_count - visited[current_planet];
        int remaining_teleports = k % cycle_length;

        current_planet = x;
        for (int j = 0; j < remaining_teleports; ++j) {
            current_planet = destinations[current_planet];
        }

        cout << current_planet << endl;
    }

    return 0;
}
