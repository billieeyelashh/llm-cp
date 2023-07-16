
#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int countBoundaryLatticePoints(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int g = gcd(dx, dy);
    return g + 1;
}

int countInsideLatticePoints(int n, int* x, int* y) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x1 = x[i];
        int y1 = y[i];
        int x2 = x[(i + 1) % n];
        int y2 = y[(i + 1) % n];
        count += countBoundaryLatticePoints(x1, y1, x2, y2) - 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int insidePoints = countInsideLatticePoints(n, x, y);
    int boundaryPoints = 0;
    for (int i = 0; i < n; i++) {
        boundaryPoints += countBoundaryLatticePoints(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
    boundaryPoints -= n;
    int area = insidePoints + boundaryPoints/2 - 1;
    cout << insidePoints << " " << boundaryPoints << endl;
    return 0;
}
