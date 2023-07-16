
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> componentSize;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    if (parentA != parentB) {
        parent[parentA] = parentB;
        componentSize[parentB] += componentSize[parentA];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    componentSize.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int largestComponent = 1;
    int numComponents = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        merge(a, b);
        
        largestComponent = max(largestComponent, componentSize[find(a)]);
        numComponents--;

        cout << numComponents << " " << largestComponent << "\n";
    }

    return 0;
}
