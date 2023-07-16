
#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct State {
    int grid[3][3];
    int moves;
};

int main() {
    int grid[3][3];

    // Read the input grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    // Define the desired grid
    int desiredGrid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Initialize the queue and visited set
    queue<State> q;
    set<State> visited;

    // Create the initial state
    State initialState;
    memcpy(initialState.grid, grid, sizeof(grid)); // Copy the grid
    initialState.moves = 0;

    // Enqueue the initial state
    q.push(initialState);
    visited.insert(initialState);

    // Perform BFS
    while (!q.empty()) {
        State currState = q.front();
        q.pop();

        // Check if the grid is in the desired state
        if (memcmp(currState.grid, desiredGrid, sizeof(desiredGrid)) == 0) {
            cout << currState.moves << endl;
            return 0;
        }

        // Generate all possible next states
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                        State nextState = currState;
                        swap(nextState.grid[i][j], nextState.grid[ni][nj]);
                        nextState.moves++;

                        // Check if the next state has been visited before
                        if (visited.find(nextState) == visited.end()) {
                            q.push(nextState);
                            visited.insert(nextState);
                        }
                    }
                }
            }
        }
    }

    // If no desired state is found
    cout << -1 << endl;

    return 0;
}
