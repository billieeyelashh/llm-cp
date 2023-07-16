
#include <iostream>
#include <string>

using namespace std;

int main() {
    string dna;
    cin >> dna;

    int n = dna.length();
    int longestRepetition = 1;
    int currentRepetition = 1;

    for (int i = 1; i < n; i++) {
        if (dna[i] == dna[i - 1]) {
            currentRepetition++;
        } else {
            longestRepetition = max(longestRepetition, currentRepetition);
            currentRepetition = 1;
        }
    }

    longestRepetition = max(longestRepetition, currentRepetition);
    cout << longestRepetition << endl;

    return 0;
}
