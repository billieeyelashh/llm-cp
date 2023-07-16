
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        auto it = tickets.lower_bound(t);
        if (it == tickets.end() || *it > t) {
            cout << -1 << endl;
        } else {
            cout << *it << endl;
            tickets.erase(it);
        }
    }

    return 0;
}
