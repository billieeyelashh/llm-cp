
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Sort the string lexicographically
    sort(s.begin(), s.end());

    vector<string> permutations;

    // Generate all permutations using next_permutation
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    // Print the number of strings
    cout << permutations.size() << endl;

    // Print the strings in alphabetical order
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
