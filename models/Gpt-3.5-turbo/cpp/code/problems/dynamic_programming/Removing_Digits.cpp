
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string numStr = to_string(n);
    int steps = 0;

    for (char c : numStr) {
        int digit = c - '0';
        n -= digit;
        steps++;
    }

    cout << steps << endl;

    return 0;
}
