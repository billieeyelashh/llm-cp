
from collections import deque

def find_shortest_path(n, m, connections):
    # Create adjacency list
    adj_list = [[] for _ in range(n+1)]
    for a, b in connections:
        adj_list[a].append(b)
        adj_list[b].append(a)

    # Initialize visited array and distance array
    visited = [False] * (n+1)
    distance = [0] * (n+1)

    # Perform BFS traversal
    queue = deque()
    queue.append(1)  # Start from Uolevi's computer
    visited[1] = True

    while queue:
        current = queue.popleft()

        for neighbor in adj_list[current]:
            if not visited[neighbor]:
                visited[neighbor] = True
                distance[neighbor] = distance[current] + 1
                queue.append(neighbor)

    if not visited[n]:
        return "IMPOSSIBLE"

    # Reconstruct the path
    path = [n]
    current = n

    while current != 1:
        for neighbor in adj_list[current]:
            if distance[neighbor] == distance[current] - 1:
                path.append(neighbor)
                current = neighbor
                break

    path.reverse()

    return distance[n], path

# Read input
n, m = map(int, input().split())
connections = [tuple(map(int, input().split())) for _ in range(m)]

# Find shortest path
result = find_shortest_path(n, m, connections)

# Print result
if isinstance(result, str):
    print(result)
else:
    k, path = result
    print(k)
    print(*path)
