
def is_safe(board, row, col):
    # Check if a queen can be placed at board[row][col]
    
    # Check the same column
    for i in range(row):
        if board[i][col] == 'Q':
            return False
    
    # Check the upper diagonal
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j -= 1
    
    # Check the lower diagonal
    i, j = row, col
    while i >= 0 and j < 8:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j += 1
    
    return True


def count_arrangements(board, row):
    # Base case: If all queens are placed, increment the count
    if row == 8:
        return 1
    
    count = 0
    
    # Try to place a queen in each column of the current row
    for col in range(8):
        if is_safe(board, row, col) and board[row][col] == '.':
            # Place the queen
            board[row][col] = 'Q'
            
            # Recur for the next row
            count += count_arrangements(board, row + 1)
            
            # Remove the queen (backtrack)
            board[row][col] = '.'
    
    return count


# Read the input chessboard
board = [list(input()) for _ in range(8)]

# Count the number of arrangements
arrangements = count_arrangements(board, 0)

# Print the result
print(arrangements)
