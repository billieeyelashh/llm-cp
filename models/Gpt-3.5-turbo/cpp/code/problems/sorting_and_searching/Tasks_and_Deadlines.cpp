
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int time = 0;
    int reward = 0;
    for (int i = 0; i < n; ++i) {
        time += tasks[i].first;
        if (time > tasks[i].second) {
            reward -= (time - tasks[i].second);
        }
    }

    cout << reward << endl;

    return 0;
}
