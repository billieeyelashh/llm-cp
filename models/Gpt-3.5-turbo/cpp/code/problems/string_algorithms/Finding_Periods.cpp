
#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefixFunction(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> findPeriodLengths(const string& s) {
    int n = s.length();
    vector<int> pi = computePrefixFunction(s);
    vector<int> periodLengths;

    // Check if n - pi[n-1] is a period length
    if (n % (n - pi[n - 1]) == 0) {
        periodLengths.push_back(n - pi[n - 1]);
    }

    // Check for other potential period lengths
    int k = n - pi[n - 1];
    while (k > 0 && pi[k - 1] > 0) {
        if (n % (k - pi[k - 1]) == 0) {
            periodLengths.push_back(k - pi[k - 1]);
        }
        k = pi[k - 1];
    }

    return periodLengths;
}

int main() {
    string s;
    cin >> s;

    vector<int> periodLengths = findPeriodLengths(s);

    // Print period lengths in increasing order
    for (int length : periodLengths) {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
