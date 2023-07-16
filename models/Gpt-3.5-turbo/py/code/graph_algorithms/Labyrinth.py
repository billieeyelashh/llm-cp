
from collections import deque

def solve_labyrinth(n, m, labyrinth):
    # Define the possible movements: left, right, up, down
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    # Find the positions of the start and end points
    start_x, start_y = None, None
    end_x, end_y = None, None
    for i in range(n):
        for j in range(m):
            if labyrinth[i][j] == 'A':
                start_x, start_y = i, j
            elif labyrinth[i][j] == 'B':
                end_x, end_y = i, j

    # Initialize the visited array and the queue for BFS
    visited = [[False] * m for _ in range(n)]
    queue = deque([(start_x, start_y, '')])
    visited[start_x][start_y] = True

    while queue:
        x, y, path = queue.popleft()

        # If we reach the end point, return the path
        if x == end_x and y == end_y:
            return "YES\n" + str(len(path)) + "\n" + path

        # Try each possible movement
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            # Check if the movement is valid and not visited
            if 0 <= nx < n and 0 <= ny < m and labyrinth[nx][ny] != '#' and not visited[nx][ny]:
                queue.append((nx, ny, path + ['L', 'R', 'U', 'D'][i]))
                visited[nx][ny] = True

    # If no path is found, return "NO"
    return "NO"

# Read the input
n, m = map(int, input().split())
labyrinth = [input() for _ in range(n)]

# Solve the labyrinth problem
print(solve_labyrinth(n, m, labyrinth))
