
#include <iostream>
#include <vector>

using namespace std;

const int p = 31; // prime number for hashing
const int m = 1e9 + 9; // large prime for modulo arithmetic

vector<int> rabin_karp(string text, vector<string>& patterns) {
    int n = text.size();
    int k = patterns.size();
    int len = patterns[0].size();

    // Compute powers of p
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    // Precompute hash values for patterns
    vector<long long> pattern_hash(k);
    for (int i = 0; i < k; i++) {
        long long hash_value = 0;
        for (int j = 0; j < len; j++)
            hash_value = (hash_value + (patterns[i][j] - 'a' + 1) * p_pow[j]) % m;
        pattern_hash[i] = hash_value;
    }

    // Compute hash values for each substring of length len in text
    vector<int> positions(k, 0);
    for (int i = 0; i <= n - len; i++) {
        long long hash_value = 0;
        for (int j = 0; j < len; j++)
            hash_value = (hash_value + (text[i + j] - 'a' + 1) * p_pow[j]) % m;

        // Check if hash value matches any pattern hash value
        for (int j = 0; j < k; j++) {
            if (hash_value == pattern_hash[j]) {
                // Confirm match by comparing substring with pattern
                bool match = true;
                for (int l = 0; l < len; l++) {
                    if (text[i + l] != patterns[j][l]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    positions[j]++;
            }
        }
    }

    return positions;
}

int main() {
    string text;
    cin >> text;

    int k;
    cin >> k;

    vector<string> patterns(k);
    for (int i = 0; i < k; i++)
        cin >> patterns[i];

    vector<int> positions = rabin_karp(text, patterns);

    for (int i = 0; i < k; i++)
        cout << positions[i] << endl;

    return 0;
}
