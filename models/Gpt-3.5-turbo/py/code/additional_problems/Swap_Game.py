
from collections import deque

def swap_tiles(state, i, j):
    # Function to swap two tiles in the grid
    new_state = list(state)
    new_state[i], new_state[j] = new_state[j], new_state[i]
    return ''.join(new_state)

def solve_puzzle(grid):
    # Convert the grid into a string
    state = ''.join(str(num) for row in grid for num in row)

    # Initialize the queue and visited set
    queue = deque([(state, 0)])
    visited = set([state])

    # Define the possible moves
    moves = [[1, 3], [0, 2, 4], [1, 5],
             [0, 4, 6], [1, 3, 5, 7], [2, 4, 8],
             [3, 7], [4, 6, 8], [5, 7]]

    while queue:
        curr_state, depth = queue.popleft()
        
        # Check if the current state matches the goal state
        if curr_state == "123456789":
            return depth
        
        # Find the index of the empty tile (denoted by 9)
        empty_tile_idx = curr_state.index("9")

        # Generate all possible moves from the current state
        for move in moves[empty_tile_idx]:
            new_state = swap_tiles(curr_state, empty_tile_idx, move)
            
            # Check if the new state has been visited before
            if new_state not in visited:
                # Enqueue the new state and update the visited set
                queue.append((new_state, depth + 1))
                visited.add(new_state)

    return -1  # Return -1 if the goal state is not reachable

# Read the input grid
grid = [list(map(int, input().split())) for _ in range(3)]

# Solve the puzzle and print the minimum number of moves
print(solve_puzzle(grid))
