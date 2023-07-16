
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int y, x;
        cin >> y >> x;
        
        long long number;
        if (x >= y) {
            if (x % 2 == 0)
                number = 1LL * x * x - (y - 1);
            else
                number = 1LL * (x - 1) * (x - 1) + y;
        } else {
            if (y % 2 == 1)
                number = 1LL * y * y - (x - 1);
            else
                number = 1LL * (y - 1) * (y - 1) + x;
        }
        
        cout << number << endl;
    }
    
    return 0;
}
