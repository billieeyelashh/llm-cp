
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> graph; // adjacency list representation of the flights

void dijkstra(int n) {
    vector<int> dist(n, INF); // initialize all distances to INF
    dist[0] = 0; // distance from Syrjälä to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // insert (distance, city) pair into the priority queue

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currCity = pq.top().second;
        pq.pop();

        if (currDist > dist[currCity]) {
            continue; // skip if we have already found a shorter route
        }

        for (auto flight : graph[currCity]) {
            int nextCity = flight.first;
            int nextDist = flight.second;

            if (currDist + nextDist < dist[nextCity]) {
                dist[nextCity] = currDist + nextDist;
                pq.push({dist[nextCity], nextCity});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n); // resize the graph to accommodate n cities

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c}); // add flight connection to the adjacency list
    }

    dijkstra(n);

    return 0;
}
