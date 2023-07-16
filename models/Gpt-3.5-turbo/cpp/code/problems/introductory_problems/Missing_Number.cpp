
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += i;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int num;
        cin >> num;
        total -= num;
    }
    
    cout << total << endl;
    
    return 0;
}
