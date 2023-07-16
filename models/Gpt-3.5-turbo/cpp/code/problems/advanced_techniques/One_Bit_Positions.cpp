
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> count(n, 0);
    int oneCount = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            oneCount++;
        }
        count[i] = oneCount;
    }

    vector<int> result(n-1, 0);

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n-k; i++) {
            if (s[i] == '1' && s[i+k] == '1') {
                result[k-1]++;
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
