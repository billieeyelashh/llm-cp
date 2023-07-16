
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    string bitString = "";

    // Iterate over all possible bit strings
    for (int i = 0; i < (1 << (n + 1)); i++) {
        string curBitString = "";
        
        // Construct the current bit string
        for (int j = 0; j < n + 1; j++) {
            if (i & (1 << j)) {
                curBitString += "1";
            } else {
                curBitString += "0";
            }
        }

        // Generate all substrings of length n from the current bit string
        for (int j = 0; j <= curBitString.length() - n; j++) {
            string substr = curBitString.substr(j, n);
            s.insert(substr);
        }
    }

    // Concatenate all the substrings to form the final bit string
    for (const string& substr : s) {
        bitString += substr;
    }

    cout << bitString << endl;

    return 0;
}
