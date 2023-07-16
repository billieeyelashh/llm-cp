
def dfs(i, j, n, m, map, visited):
    if i < 0 or i >= n or j < 0 or j >= m:
        return
    if visited[i][j]:
        return
    if map[i][j] == '#':
        return

    visited[i][j] = True

    # Recursively explore adjacent floor squares
    dfs(i+1, j, n, m, map, visited)
    dfs(i-1, j, n, m, map, visited)
    dfs(i, j+1, n, m, map, visited)
    dfs(i, j-1, n, m, map, visited)

def count_rooms(n, m, map):
    visited = [[False] * m for _ in range(n)]
    count = 0

    for i in range(n):
        for j in range(m):
            if not visited[i][j] and map[i][j] == '.':
                dfs(i, j, n, m, map, visited)
                count += 1

    return count

# Read input
n, m = map(int, input().split())
map = [input() for _ in range(n)]

# Count rooms
rooms = count_rooms(n, m, map)

# Print result
print(rooms)
