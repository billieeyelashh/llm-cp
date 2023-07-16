
#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> findBorders(string s) {
    vector<int> lps = computeLPS(s);
    int n = s.length();
    vector<int> borders;

    for (int i = 0; i < n - 1; i++) {
        if (lps[i] > 0 && lps[i] == n - i - 1) {
            borders.push_back(lps[i]);
        }
    }

    return borders;
}

int main() {
    string s;
    cin >> s;

    vector<int> borders = findBorders(s);

    for (int border : borders) {
        cout << border << " ";
    }

    return 0;
}
