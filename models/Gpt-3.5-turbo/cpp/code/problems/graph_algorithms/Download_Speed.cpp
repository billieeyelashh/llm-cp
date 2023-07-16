
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Data structure to represent an edge
struct Edge {
    int to;
    int capacity;
    int flow;
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int from, int to, int capacity) {
    graph[from].push_back({to, capacity, 0});
    graph[to].push_back({from, 0, 0}); // Add reverse edge with capacity 0 for residual graph
}

// Function to find the maximum flow from source to sink using Ford-Fulkerson algorithm
int findMaxFlow(vector<vector<Edge>>& graph, int source, int sink) {
    int n = graph.size();
    vector<int> parent(n);
    int maxFlow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;

        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int curr = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (const Edge& edge : graph[curr]) {
                int to = edge.to;
                int capacity = edge.capacity;
                int residual = capacity - edge.flow;

                if (parent[to] == -1 && residual > 0) {
                    parent[to] = curr;
                    int newFlow = min(flow, residual);
                    if (to == sink) {
                        maxFlow += newFlow;
                        while (to != source) {
                            curr = parent[to];
                            for (Edge& e : graph[curr]) {
                                if (e.to == to) {
                                    e.flow += newFlow;
                                    break;
                                }
                            }
                            for (Edge& e : graph[to]) {
                                if (e.to == curr) {
                                    e.flow -= newFlow;
                                    break;
                                }
                            }
                            to = curr;
                        }
                        break;
                    }
                    q.push({to, newFlow});
                }
            }

            if (parent[sink] != -1) {
                break;
            }
        }

        if (parent[sink] == -1) {
            break;
        }
    }

    return maxFlow;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(graph, a, b, c);
    }

    int source = 1;
    int sink = n;
    int maxFlow = findMaxFlow(graph, source, sink);

    cout << maxFlow << endl;

    return 0;
}
