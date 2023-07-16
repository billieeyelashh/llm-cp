
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int p = 31;
const int m = 1e9 + 9;

vector<int> pattern_positions(const string& s, const vector<string>& patterns) {
    int n = s.size();
    int k = patterns.size();

    // Precompute powers of p
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Compute hash values for all prefixes of s
    vector<long long> hash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    unordered_map<long long, int> pattern_hash_map;
    for (int i = 0; i < k; i++) {
        string pattern = patterns[i];
        int pattern_len = pattern.size();

        // Compute hash value for the pattern
        long long pattern_hash = 0;
        for (int j = 0; j < pattern_len; j++) {
            pattern_hash = (pattern_hash + (pattern[j] - 'a' + 1) * p_pow[j]) % m;
        }

        pattern_hash_map[pattern_hash] = i;
    }

    vector<int> positions(k, -1);
    for (int i = 0; i <= n - pattern_len; i++) {
        // Compute hash value for the current substring
        long long substring_hash = (hash[i + pattern_len] + m - hash[i]) % m;
        if (pattern_hash_map.count(substring_hash)) {
            int pattern_index = pattern_hash_map[substring_hash];
            if (positions[pattern_index] == -1) {
                positions[pattern_index] = i + 1;
            }
        }
    }

    return positions;
}

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> patterns(k);
    for (int i = 0; i < k; i++) {
        cin >> patterns[i];
    }

    vector<int> result = pattern_positions(s, patterns);

    for (int i = 0; i < k; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
