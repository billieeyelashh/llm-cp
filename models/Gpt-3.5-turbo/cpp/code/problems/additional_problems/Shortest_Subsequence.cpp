
#include <iostream>
#include <string>

using namespace std;

int main() {
    string dna_sequence;
    cin >> dna_sequence;

    string shortest_sequence;
    for (char c : dna_sequence) {
        if (c == 'A') {
            shortest_sequence += "T";
        } else if (c == 'T') {
            shortest_sequence += "A";
        } else if (c == 'C') {
            shortest_sequence += "G";
        } else if (c == 'G') {
            shortest_sequence += "C";
        }
    }

    cout << shortest_sequence << endl;

    return 0;
}
