
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size() || visited[x][y])
        return;

    visited[x][y] = true;

    if (map[x][y] == '#')
        return;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    map.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}
