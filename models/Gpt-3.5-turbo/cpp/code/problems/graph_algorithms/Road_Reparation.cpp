
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int city1;
    int city2;
    int cost;
};

bool compareRoads(const Road& r1, const Road& r2) {
    return r1.cost < r2.cost;
}

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return false;
    parent[px] = py;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].city1 >> roads[i].city2 >> roads[i].cost;
    }

    sort(roads.begin(), roads.end(), compareRoads);

    parent.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<Road> minimumSpanningTree;
    int totalCost = 0;

    for (int i = 0; i < m; i++) {
        if (unite(roads[i].city1, roads[i].city2)) {
            minimumSpanningTree.push_back(roads[i]);
            totalCost += roads[i].cost;
        }
        if (minimumSpanningTree.size() == n-1) break;
    }

    if (minimumSpanningTree.size() != n-1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << totalCost << endl;
    }

    return 0;
}
