
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int area = 0;

    for (int i = 0; i < n; i++) {
        area += x[i] * y[(i + 1) % n];
        area -= y[i] * x[(i + 1) % n];
    }

    cout << abs(area) << endl;

    return 0;
}
