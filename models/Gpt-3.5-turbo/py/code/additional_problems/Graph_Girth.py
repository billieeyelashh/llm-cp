
from collections import deque

def bfs(graph, start):
    n = len(graph)
    queue = deque([(start, 0)])
    visited = [False] * n
    visited[start] = True

    while queue:
        node, dist = queue.popleft()

        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append((neighbor, dist + 1))
                visited[neighbor] = True

            # Check if we have found a cycle
            elif neighbor == start:
                return dist + 1

    return float('inf')

def find_girth(graph, n):
    girth = float('inf')

    for i in range(n):
        cycle_len = bfs(graph, i)
        girth = min(girth, cycle_len)

    return girth if girth != float('inf') else -1

# Read input
n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

# Find and print the girth
girth = find_girth(graph, n)
print(girth)
