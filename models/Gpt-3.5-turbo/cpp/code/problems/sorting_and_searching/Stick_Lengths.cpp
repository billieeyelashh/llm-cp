
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total_length = 0;
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        total_length += length;
    }
    
    int average_length = total_length / n;
    
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        total_cost += abs(length - average_length);
    }
    
    cout << total_cost << endl;
    
    return 0;
}
