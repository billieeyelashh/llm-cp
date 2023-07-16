
#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void unionSet(int x, int y, vector<int>& parent) {
    int px = find(x, parent);
    int py = find(y, parent);
    if (px != py) {
        parent[py] = px;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connections[i] = {a, b};
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < m; j++) {
            if (connections[j].first != a || connections[j].second != b) {
                unionSet(connections[j].first, connections[j].second, parent);
            }
        }
        int components = 0;
        for (int j = 1; j <= n; j++) {
            if (parent[j] == j) {
                components++;
            }
        }
        cout << components << " ";
        m--;
    }

    cout << endl;

    return 0;
}
