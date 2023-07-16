
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int y, int x, int ty, int tx, vector<vector<bool>>& visited, string& path) {
    if (y == ty && x == tx) {
        cout << "YES\n" << path << "\n";
        return true;
    }

    visited[y][x] = true;

    // Try moving up
    if (y > 1 && !visited[y - 1][x] && !(y - 1 == ty && x == tx)) {
        path += 'U';
        if (dfs(y - 1, x, ty, tx, visited, path)) {
            return true;
        }
        path.pop_back();
    }

    // Try moving down
    if (y < visited.size() - 1 && !visited[y + 1][x] && !(y + 1 == ty && x == tx)) {
        path += 'D';
        if (dfs(y + 1, x, ty, tx, visited, path)) {
            return true;
        }
        path.pop_back();
    }

    // Try moving left
    if (x > 1 && !visited[y][x - 1] && !(y == ty && x - 1 == tx)) {
        path += 'L';
        if (dfs(y, x - 1, ty, tx, visited, path)) {
            return true;
        }
        path.pop_back();
    }

    // Try moving right
    if (x < visited[0].size() - 1 && !visited[y][x + 1] && !(y == ty && x + 1 == tx)) {
        path += 'R';
        if (dfs(y, x + 1, ty, tx, visited, path)) {
            return true;
        }
        path.pop_back();
    }

    visited[y][x] = false;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, y1, x1, y2, x2;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;

        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
        string path = "";

        if (!dfs(y1, x1, y2, x2, visited, path)) {
            cout << "NO\n";
        }
    }

    return 0;
}
