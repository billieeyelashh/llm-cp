
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, weight;
};

const int INF = 1e9;

vector<int> bellmanFord(int n, vector<Edge>& edges) {
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge& edge : edges) {
            if (dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = max(-INF, dist[edge.from] + edge.weight);
                parent[edge.to] = edge.from;
                x = edge.to;
            }
        }
    }

    if (x == -1) {
        return {};
    }

    for (int i = 0; i < n; ++i) {
        x = parent[x];
    }

    vector<int> cycle;
    for (int v = x;; v = parent[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) {
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<int> cycle = bellmanFord(n, edges);
    if (cycle.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
