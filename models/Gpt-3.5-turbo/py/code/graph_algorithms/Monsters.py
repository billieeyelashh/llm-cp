
from collections import deque

# Read input values
n, m = map(int, input().split())

# Read labyrinth map
maze = [list(input()) for _ in range(n)]

# Initialize variables
possible = False
visited = [[False] * m for _ in range(n)]
path = [['.'] * m for _ in range(n)]
directions = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
start_pos = None

# Find the starting position
for i in range(n):
    for j in range(m):
        if maze[i][j] == 'A':
            start_pos = (i, j)
            break

# Run BFS traversal
queue = deque([start_pos])
visited[start_pos[0]][start_pos[1]] = True

while queue:
    x, y = queue.popleft()

    # Check if it's a boundary square
    if x == 0 or x == n - 1 or y == 0 or y == m - 1:
        possible = True
        break

    # Check adjacent positions
    for dx, dy in directions.values():
        nx, ny = x + dx, y + dy

        # Check if position is valid
        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and maze[nx][ny] != '#':
            queue.append((nx, ny))
            visited[nx][ny] = True
            path[nx][ny] = next(dir for dir, (ddx, ddy) in directions.items() if dx == ddx and dy == ddy)

# Print the result
if possible:
    print("YES")
    steps = sum(row.count('.') for row in path)
    print(steps)
    x, y = next((i, j) for i in range(n) for j in range(m) if maze[i][j] == 'A')
    while path[x][y] != '.':
        print(path[x][y], end='')
        dx, dy = directions[path[x][y]]
        x, y = x + dx, y + dy
else:
    print("NO")
