
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back(curr);

        for (int adj : graph[curr]) {
            indegree[adj]--;
            if (indegree[adj] == 0) {
                q.push(adj);
            }
        }
    }

    if (order.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
