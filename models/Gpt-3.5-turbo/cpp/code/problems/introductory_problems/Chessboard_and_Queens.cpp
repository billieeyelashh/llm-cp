
#include <iostream>
using namespace std;

const int N = 8; // size of the chessboard
int count = 0; // variable to store the count of valid placements

bool isSafe(int row, int col, char board[N][N]) {
    // check if there is a queen in the same row or same column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == 'Q' || board[i][col] == 'Q') {
            return false;
        }
    }
    
    // check if there is a queen in the diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    
    return true;
}

void solve(int row, char board[N][N]) {
    // if all queens are placed, increment the count
    if (row == N) {
        count++;
        return;
    }
    
    // try placing the queen in each column of the current row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == '.' && isSafe(row, i, board)) {
            board[row][i] = 'Q'; // place the queen
            
            // recursively move to the next row
            solve(row + 1, board);
            
            board[row][i] = '.'; // backtrack and remove the queen
        }
    }
}

int main() {
    char board[N][N];
    
    // read the input chessboard
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(0, board);
    
    cout << count << endl;
    
    return 0;
}
