
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> toppings(m, '+');

    for (int i = 0; i < n; i++) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            toppings[x - 1] = '+';
        } else {
            toppings[x - 1] = '-';
        }
    }

    bool hasEmpty = false;
    for (char c : toppings) {
        if (c != '+' && c != '-') {
            hasEmpty = true;
            break;
        }
    }

    if (hasEmpty) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (char c : toppings) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
