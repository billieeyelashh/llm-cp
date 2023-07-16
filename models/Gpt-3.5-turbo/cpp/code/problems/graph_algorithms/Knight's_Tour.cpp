
#include <iostream>
#include <vector>

using namespace std;

// Global variables to represent the chessboard and the current knight position
vector<vector<int>> board(8, vector<int>(8, 0));
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// Function to check if a move is valid
bool isValidMove(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0);
}

// Recursive function to find the knight's tour
bool findKnightTour(int x, int y, int count) {
    // Mark the current square as visited
    board[x][y] = count;

    // Base case: if all squares are visited, return true
    if (count == 64) {
        return true;
    }

    // Try all possible moves from the current position
    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Check if the next move is valid
        if (isValidMove(nextX, nextY)) {
            // Recursive call to explore the next move
            if (findKnightTour(nextX, nextY, count + 1)) {
                return true;
            }
        }
    }

    // If no valid move is found, backtrack and reset the current square
    board[x][y] = 0;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;

    // Start the knight's tour from the given position
    findKnightTour(x - 1, y - 1, 1);

    // Print the knight's tour
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
