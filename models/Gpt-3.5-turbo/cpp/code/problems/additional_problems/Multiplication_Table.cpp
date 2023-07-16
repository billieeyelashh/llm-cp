
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int middleElement = (n + 1) / 2;
    int middleValue = middleElement * middleElement;

    cout << middleValue << endl;

    return 0;
}
