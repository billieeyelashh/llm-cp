
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> groupSize;

int findParent(int node) {
    if (parent[node] == node)
        return node;

    // Path compression
    return parent[node] = findParent(parent[node]);
}

void unionGroups(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);

    if (parentA == parentB)
        return;

    // Union by size
    if (groupSize[parentA] < groupSize[parentB]) {
        swap(parentA, parentB);
    }

    parent[parentB] = parentA;
    groupSize[parentA] += groupSize[parentB];
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    groupSize.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionGroups(a, b);
    }

    vector<int> result(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int parentI = findParent(i);
        result[parentI] = groupSize[parentI];
    }

    for (int i = 1; i <= n; i++) {
        cout << (result[i] > 0 ? 1 : 0);
    }
    cout << endl;

    return 0;
}
