
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first; // we store ending time as second and starting time as first
    }

    sort(movies.begin(), movies.end());

    int answer = 0;
    int latestEndingTime = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].second >= latestEndingTime) {
            answer++;
            latestEndingTime = movies[i].first;
        }
    }

    cout << answer << endl;

    return 0;
}
