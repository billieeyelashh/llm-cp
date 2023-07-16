
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int subordinates[MAXN];

void dfs(int employee) {
    for (int subordinate : adj[employee]) {
        dfs(subordinate);
        subordinates[employee] += subordinates[subordinate] + 1;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }

    return 0;
}
