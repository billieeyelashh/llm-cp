
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_algorithm(const string& s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> kmp_algorithm(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z = z_algorithm(s);
    vector<int> pi = kmp_algorithm(s);
    for (int i = 0; i < n; ++i) {
        cout << z[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << pi[i] << ' ';
    }
    cout << '\n';
    return 0;
}
