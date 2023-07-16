
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;

void dfs(int course) {
    visited[course] = true;
    
    for (int nextCourse : graph[course]) {
        if (!visited[nextCourse]) {
            dfs(nextCourse);
        }
    }
    
    order.push_back(course);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    dfs(1);
    
    for (int i = n - 1; i >= 0; i--) {
        cout << order[i] << " ";
    }
    
    return 0;
}
