
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    cout << n / 2 << endl;

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    cout << n / 2 - 1 << endl;

    for (int i = 1; i <= n - 1; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
