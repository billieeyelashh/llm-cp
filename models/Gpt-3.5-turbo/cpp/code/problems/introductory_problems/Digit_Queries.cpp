
#include <iostream>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        long long k;
        cin >> k;

        int n = 1;
        int len = 1;

        while (k > len) {
            k -= len;
            ++n;
            len = to_string(n).size();
        }

        string num = to_string(n);
        cout << num[k - 1] << endl;
    }

    return 0;
}
