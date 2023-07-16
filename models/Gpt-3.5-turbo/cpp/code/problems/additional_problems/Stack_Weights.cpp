
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int left = 1, right = n;

    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;

        if (s == 1) {
            right = c - 1;
        } else {
            left = c + 1;
        }

        if (left > right) {
            cout << "<\n";
        } else if (left < right) {
            cout << ">\n";
        } else {
            cout << "?\n";
        }
    }

    return 0;
}
