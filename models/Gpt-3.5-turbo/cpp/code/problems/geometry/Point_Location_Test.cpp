
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        long long cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        
        if (cross_product > 0) {
            cout << "LEFT\n";
        } else if (cross_product < 0) {
            cout << "RIGHT\n";
        } else {
            cout << "TOUCH\n";
        }
    }

    return 0;
}
