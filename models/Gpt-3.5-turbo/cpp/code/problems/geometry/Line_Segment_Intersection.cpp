
#include <iostream>
using namespace std;

// Function to calculate the orientation of three points
int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (val == 0)
        return 0; // Collinear
    else if (val > 0)
        return 1; // Clockwise
    else
        return 2; // Counterclockwise
}

// Function to check if two line segments intersect
bool doLineSegmentsIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int orientation1 = orientation(x1, y1, x2, y2, x3, y3);
    int orientation2 = orientation(x1, y1, x2, y2, x4, y4);
    int orientation3 = orientation(x3, y3, x4, y4, x1, y1);
    int orientation4 = orientation(x3, y3, x4, y4, x2, y2);

    // If the orientations are different, the line segments intersect
    if (orientation1 != orientation2 && orientation3 != orientation4)
        return true;

    // Special cases for collinear points
    if (orientation1 == 0 && x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2))
        return true;
    if (orientation2 == 0 && x4 >= min(x1, x2) && x4 <= max(x1, x2) && y4 >= min(y1, y2) && y4 <= max(y1, y2))
        return true;
    if (orientation3 == 0 && x1 >= min(x3, x4) && x1 <= max(x3, x4) && y1 >= min(y3, y4) && y1 <= max(y3, y4))
        return true;
    if (orientation4 == 0 && x2 >= min(x3, x4) && x2 <= max(x3, x4) && y2 >= min(y3, y4) && y2 <= max(y3, y4))
        return true;

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (doLineSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
