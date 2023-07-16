
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Position {
    int row, col;
};

// Function to check if a position is valid
bool isValid(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

// Function to find the path from start to boundary square
vector<char> findPath(vector<vector<char>>& labyrinth, int n, int m, Position start) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Position>> parent(n, vector<Position>(m));

    // Possible moves: down, up, right, left
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    char moves[] = {'D', 'U', 'R', 'L'};

    queue<Position> q;
    q.push(start);
    visited[start.row][start.col] = true;

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + dr[i];
            int newCol = curr.col + dc[i];

            if (isValid(newRow, newCol, n, m) && labyrinth[newRow][newCol] != '#' && !visited[newRow][newCol]) {
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = curr;

                if (newRow == 0 || newRow == n - 1 || newCol == 0 || newCol == m - 1) {
                    // Backtrack to start position to find the path
                    vector<char> path;
                    Position pos = {newRow, newCol};

                    while (pos.row != start.row || pos.col != start.col) {
                        Position prevPos = parent[pos.row][pos.col];
                        if (prevPos.row < pos.row) path.push_back('U');
                        else if (prevPos.row > pos.row) path.push_back('D');
                        else if (prevPos.col < pos.col) path.push_back('L');
                        else path.push_back('R');
                        pos = prevPos;
                    }

                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }

    return {}; // If no valid path is found
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> labyrinth(n, vector<char>(m));
    Position start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];

            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    vector<char> path = findPath(labyrinth, n, m, start);
    if (!path.empty()) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (char move : path) {
            cout << move;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
