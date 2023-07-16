
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int inc = 0, dec = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            inc++;
        } else if (arr[i] < arr[i - 1]) {
            dec++;
        }
    }
    
    int minMoves = min(inc, dec);
    cout << minMoves << endl;
    
    return 0;
}
