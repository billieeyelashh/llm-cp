
#include <iostream>
#include <unordered_set>

using namespace std;

const int p = 31;
const int m = 1e9 + 9;

bool check(string& s, int len) {
    unordered_set<int> hashes;
    long long curr_hash = 0;
    long long power = 1;

    for (int i = 0; i < len; i++) {
        curr_hash = (curr_hash * p + (s[i] - 'a' + 1)) % m;
        power = (power * p) % m;
    }
    hashes.insert(curr_hash);

    for (int i = len; i < s.length(); i++) {
        curr_hash = (curr_hash * p - (s[i - len] - 'a' + 1) * power + (s[i] - 'a' + 1) + m) % m;
        if (hashes.find(curr_hash) != hashes.end()) {
            return true;
        }
        hashes.insert(curr_hash);
    }

    return false;
}

string longestRepeatingSubstring(string& s) {
    int low = 1;
    int high = s.length();
    string ans = "";

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(s, mid)) {
            ans = s.substr(0, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    string result = longestRepeatingSubstring(s);
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
