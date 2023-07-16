
#include <iostream>
#include <string>

using namespace std;

string lexicographicallyMinimalRotation(string s) {
    s += s; // concatenate the string with itself

    int n = s.length();
    int i = 0, j = 1, k = 0;

    while (i + k < n && j + k < n) {
        if (s[i + k] == s[j + k])
            k++;
        else if (s[i + k] > s[j + k]) {
            i = i + k + 1;
            if (i <= j)
                i = j + 1;
            k = 0;
        } else {
            j = j + k + 1;
            if (j <= i)
                j = i + 1;
            k = 0;
        }
    }

    int rotationIndex = min(i, j);
    return s.substr(rotationIndex, n / 2);
}

int main() {
    string s;
    cin >> s;

    string result = lexicographicallyMinimalRotation(s);
    cout << result << endl;

    return 0;
}
