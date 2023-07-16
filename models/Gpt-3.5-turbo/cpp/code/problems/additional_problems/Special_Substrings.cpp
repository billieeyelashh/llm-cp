
#include <iostream>
#include <vector>

using namespace std;

int countSpecialSubstrings(string s) {
    int n = s.length();
    vector<int> count(26), freq(n + 1);
    int left = 0, right = 0;
    int specialCount = 0;

    while (left < n) {
        while (right < n && (right == left || count[s[right] - 'a'] + 1 == count[s[right - 1] - 'a'])) {
            count[s[right] - 'a']++;
            freq[count[s[right] - 'a']]++;
            right++;
        }

        specialCount += freq[left + 1];

        int k = 2;
        while (left + k <= right && count[s[left + k - 1] - 'a'] == count[s[left + k - 2] - 'a']) {
            specialCount++;
            k++;
        }

        count[s[left] - 'a']--;
        freq[count[s[left] - 'a']]--;

        left++;
    }

    return specialCount;
}

int main() {
    string s;
    cin >> s;

    int result = countSpecialSubstrings(s);
    cout << result << endl;

    return 0;
}
