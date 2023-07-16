
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool isOnBoundary(const Point& p, const Point& a, const Point& b) {
    if (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
        p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) {
        return true;
    }
    return false;
}

int countIntersections(const Point& p, const Point& a, const Point& b) {
    if (isOnBoundary(p, a, b)) {
        return 0;
    }

    int intersections = 0;

    // Check if the line segment intersects with the ray
    if ((a.y > p.y && b.y <= p.y) || (b.y > p.y && a.y <= p.y)) {
        // Calculate the x-coordinate of the intersection point
        double x = a.x + (double(p.y - a.y) / double(b.y - a.y)) * (b.x - a.x);
        if (x > p.x) {
            intersections++;
        }
    }

    return intersections;
}

string pointLocation(const Point& p, const vector<Point>& polygon) {
    int intersections = 0;
    int n = polygon.size();

    // Check each edge of the polygon
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        intersections += countIntersections(p, polygon[i], polygon[j]);
    }

    if (intersections % 2 == 1) {
        return "INSIDE";
    } else if (intersections == 0) {
        return "BOUNDARY";
    } else {
        return "OUTSIDE";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y;
        cout << pointLocation(p, polygon) << endl;
    }

    return 0;
}
