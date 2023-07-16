
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> components;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
        components[a]--;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    parent.resize(n + 1);
    components.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for (int i = 0; i <= k; i++) {
        cout << components[find(1)] << " ";

        if (i != k) {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 1) {
                merge(a, b);
            }
        }
    }

    return 0;
}
