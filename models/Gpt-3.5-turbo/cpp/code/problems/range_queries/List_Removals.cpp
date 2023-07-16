
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> lst;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lst.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << lst[p-1] << " ";
        lst.erase(lst.begin() + (p-1));
    }

    return 0;
}
