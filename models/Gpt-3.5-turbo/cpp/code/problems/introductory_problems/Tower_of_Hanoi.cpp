
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves; // to store the moves

void towerOfHanoi(int n, int source, int target, int auxiliary) {
    if (n > 0) {
        // Move n-1 disks from source to auxiliary
        towerOfHanoi(n - 1, source, auxiliary, target);
        
        // Move the nth disk from source to target
        moves.push_back({source, target});

        // Move the n-1 disks from auxiliary to target
        towerOfHanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    int n;
    cin >> n;
    
    towerOfHanoi(n, 1, 3, 2); // start from source stack 1, target stack 3, and auxiliary stack 2
    
    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }
    
    return 0;
}
