
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};

bool compare(Point p1, Point p2) {
    // Compare points based on counterclockwise order with respect to the starting point
    int orientation = (p1.y - start.y) * (p2.x - start.x) - (p1.x - start.x) * (p2.y - start.y);
    if (orientation != 0)
        return orientation > 0;
    
    // If the points are collinear, choose the one closest to the starting point
    int dist1 = (p1.x - start.x) * (p1.x - start.x) + (p1.y - start.y) * (p1.y - start.y);
    int dist2 = (p2.x - start.x) * (p2.x - start.x) + (p2.y - start.y) * (p2.y - start.y);
    return dist1 < dist2;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    
    // Find the starting point
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    }
    swap(points[0], points[minIndex]);
    Point start = points[0];
    
    // Sort the remaining points
    sort(points.begin() + 1, points.end(), compare);
    
    // Build the convex hull using a stack
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            Point top = hull.top();
            hull.pop();
            Point secondTop = hull.top();
            
            int orientation = (points[i].y - secondTop.y) * (top.x - secondTop.x) - (points[i].x - secondTop.x) * (top.y - secondTop.y);
            if (orientation > 0) {
                hull.push(top);
                break;
            }
        }
        hull.push(points[i]);
    }
    
    // Convert the stack to a vector
    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    
    cout << hull.size() << endl;
    for (int i = 0; i < hull.size(); i++) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }
    
    return 0;
}
