
#include <iostream>
#include <string>
using namespace std;

int countOccurrences(string s, string pattern) {
    int n = s.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        if (s.substr(i, m) == pattern) {
            count++;
        }
    }

    return count;
}

int main() {
    string s, pattern;
    cin >> s >> pattern;

    int occurrences = countOccurrences(s, pattern);
    cout << occurrences << endl;

    return 0;
}
