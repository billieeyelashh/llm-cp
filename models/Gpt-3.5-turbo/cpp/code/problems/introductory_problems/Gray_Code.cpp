
#include <iostream>
#include <vector>
using namespace std;

void generateGrayCode(int n) {
    // Base case: Gray code for n = 1
    if (n == 1) {
        cout << "0\n1\n";
        return;
    }

    // Recursive case: Generate Gray code for n-1
    generateGrayCode(n - 1);

    // Append the reverse of Gray code for n-1
    vector<string> grayCode = {"0", "1"};
    for (int i = grayCode.size() - 1; i >= 0; i--) {
        cout << grayCode[i] << "\n";
        grayCode.push_back("1" + grayCode[i]);
        grayCode[i] = "0" + grayCode[i];
    }
}

int main() {
    int n;
    cin >> n;

    generateGrayCode(n);

    return 0;
}
