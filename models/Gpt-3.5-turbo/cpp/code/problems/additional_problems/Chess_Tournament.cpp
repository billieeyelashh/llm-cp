
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> players; // (number of games, player number)

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        players.push_back({x, i});
    }

    sort(players.begin(), players.end());

    vector<pair<int, int>> games;

    for (int i = 0; i < n; ++i) {
        int numGames = players[i].first;
        int player = players[i].second;

        for (int j = 0; j < numGames; ++j) {
            if (i + j + 1 >= n) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            int opponent = players[i + j + 1].second;
            games.push_back({player, opponent});
        }
    }

    cout << games.size() << endl;
    for (auto& game : games) {
        cout << game.first << " " << game.second << endl;
    }

    return 0;
}
