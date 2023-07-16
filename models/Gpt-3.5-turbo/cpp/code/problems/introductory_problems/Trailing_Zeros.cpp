
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int zeros = 0;
    int powerOfFive = 5;

    while (powerOfFive <= n) {
        zeros += n / powerOfFive;
        powerOfFive *= 5;
    }

    cout << zeros << endl;

    return 0;
}
