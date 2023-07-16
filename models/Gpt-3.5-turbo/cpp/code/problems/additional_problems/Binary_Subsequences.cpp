
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "0";
    for (int i = 1; i < n; i++) {
        ans += (i % 2 == 0) ? "0" : "1";
    }

    if (n % 2 == 1) {
        ans += "1";
    }

    cout << ans << endl;

    return 0;
}
