
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int x, y, type;
};

bool cmp(const Event& a, const Event& b) {
    if (a.x == b.x) {
        return a.type < b.type;
    }
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        events.push_back({x1, y1, 0});
        events.push_back({x2, y2, 1});
    }

    sort(events.begin(), events.end(), cmp);

    int intersections = 0;
    set<pair<int, int>> active;
    for (const Event& event : events) {
        if (event.type == 0) {
            for (const pair<int, int>& line : active) {
                if (line.second > event.y && line.first < event.x) {
                    intersections++;
                }
            }
            active.insert({event.y, event.x});
        } else {
            active.erase({event.y, event.x});
        }
    }

    cout << intersections << endl;

    return 0;
}
