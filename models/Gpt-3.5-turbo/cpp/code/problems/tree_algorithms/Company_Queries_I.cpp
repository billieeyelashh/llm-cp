
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> level;

void dfs(int employee, int boss) {
    level[employee] = level[boss] + 1;

    for (int subordinate : tree[employee]) {
        dfs(subordinate, employee);
    }
}

int findBoss(int x, int k) {
    while (k > 0 && x != 1) {
        x = tree[x][0];
        k--;
    }

    if (k == 0) {
        return x;
    } else {
        return -1;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    tree.resize(n + 1);
    level.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }

    dfs(1, 0);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findBoss(x, k) << endl;
    }

    return 0;
}
