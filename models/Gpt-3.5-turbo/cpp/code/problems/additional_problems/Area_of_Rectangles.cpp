
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

bool cmp(const Rectangle& r1, const Rectangle& r2) {
    return r1.x1 < r2.x1 || (r1.x1 == r2.x1 && r1.y1 < r2.y1);
}

int main() {
    int n;
    cin >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
    }

    sort(rectangles.begin(), rectangles.end(), cmp);

    long long ans = 0;
    int prevX = rectangles[0].x1;
    multiset<int> activeSet;
    activeSet.insert(rectangles[0].y1);

    for (int i = 1; i < n; i++) {
        ans += 1LL * (rectangles[i].x1 - prevX) * (*activeSet.rbegin());

        prevX = rectangles[i].x1;

        if (rectangles[i].x1 == rectangles[i - 1].x1) {
            activeSet.insert(rectangles[i].y1);
        } else {
            for (auto it = activeSet.begin(); it != activeSet.end(); ) {
                if (*it >= rectangles[i].x1) {
                    break;
                }
                activeSet.erase(it++);
            }
            activeSet.insert(rectangles[i].y1);
        }

        activeSet.erase(activeSet.find(rectangles[i].y2));
    }

    cout << ans << endl;

    return 0;
}
