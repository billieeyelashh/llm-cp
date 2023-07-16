
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, INT_MAX);
    distances[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > distances[u]) {
            continue;
        }

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        graph[b-1].push_back({a-1, c});
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        vector<int> distances;
        dijkstra(graph, a-1, distances);

        int shortest_distance = distances[b-1];
        if (shortest_distance == INT_MAX) {
            shortest_distance = -1;
        }

        cout << shortest_distance << endl;
    }

    return 0;
}
