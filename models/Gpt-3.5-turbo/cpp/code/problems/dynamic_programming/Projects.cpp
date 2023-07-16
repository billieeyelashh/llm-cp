
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& p1, const vector<int>& p2) {
    return p1[1] < p2[1];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    sort(projects.begin(), projects.end(), compare);

    int maxMoney = 0;
    int lastAttendedDay = 0;
    for (int i = 0; i < n; i++) {
        if (projects[i][0] > lastAttendedDay) {
            maxMoney += projects[i][2];
            lastAttendedDay = projects[i][1];
        }
    }

    cout << maxMoney << endl;

    return 0;
}
