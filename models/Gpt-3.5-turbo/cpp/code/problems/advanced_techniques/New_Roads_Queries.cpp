
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "Connected after " << m << " roads" << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
