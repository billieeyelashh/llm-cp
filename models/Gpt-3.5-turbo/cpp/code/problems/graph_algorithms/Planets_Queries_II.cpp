
#include <iostream>
#include <vector>

using namespace std;

vector<int> destinations;
vector<bool> visited;

int dfs(int planet, int destination) {
    if (planet == destination) {
        return 0; // Reached the destination planet
    }
    
    if (visited[planet]) {
        return -1; // Already visited this planet, not possible to reach the destination
    }
    
    visited[planet] = true;
    int nextPlanet = destinations[planet];
    int result = dfs(nextPlanet, destination);
    visited[planet] = false; // Reset visited status for backtracking
    
    if (result == -1) {
        return -1; // Not possible to reach the destination from the next planet
    }
    
    return result + 1; // Add 1 to the result since we traversed one edge
}

int main() {
    int n, q;
    cin >> n >> q;
    
    destinations.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> destinations[i];
        destinations[i]--; // Adjusting 0-based indexing
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Adjusting 0-based indexing
        
        visited.assign(n, false);
        int result = dfs(a, b);
        
        cout << result << endl;
    }
    
    return 0;
}
