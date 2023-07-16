
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    int components;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = findRoot(parent[x]);
    }

    void merge(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            components--;
        }
    }

    int getComponents() {
        return components;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    UnionFind uf(n);

    vector<int> rounds(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        uf.merge(arr[a], arr[b]);
        rounds[i] = uf.getComponents();
    }

    for (int round : rounds) {
        cout << round << endl;
    }

    return 0;
}
