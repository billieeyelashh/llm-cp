
def is_valid_move(x, y):
    return 1 <= x <= 8 and 1 <= y <= 8

def dfs(x, y, count, visited, moves):
    # Mark the current square as visited
    visited[x][y] = True
    
    # Add the current square to the moves array
    moves.append((x, y))
    
    # If all squares have been visited, return True
    if count == 64:
        return True
    
    # Possible knight moves
    dx = [2, 1, -1, -2, -2, -1, 1, 2]
    dy = [1, 2, 2, 1, -1, -2, -2, -1]
    
    # Try all possible moves from the current square
    for i in range(8):
        new_x = x + dx[i]
        new_y = y + dy[i]
        
        # Check if the move is valid and the square has not been visited yet
        if is_valid_move(new_x, new_y) and not visited[new_x][new_y]:
            # Recursive call to explore the next square
            if dfs(new_x, new_y, count+1, visited, moves):
                return True
    
    # Backtrack: remove the last move from the moves array and mark the current square as unvisited
    moves.pop()
    visited[x][y] = False
    
    return False

# Read the input
x, y = map(int, input().split())

# Create the visited array
visited = [[False] * 9 for _ in range(9)]

# Create the moves array
moves = []

# Call the DFS function to find the sequence of moves
dfs(x, y, 1, visited, moves)

# Print the moves array
for move in moves:
    print(move[0], move[1], end=' ')
