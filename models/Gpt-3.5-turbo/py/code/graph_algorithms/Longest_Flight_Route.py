
from collections import defaultdict

def dfs(graph, visited, city):
    visited[city] = True
    path = [city]

    for neighbor in graph[city]:
        if not visited[neighbor]:
            path += dfs(graph, visited, neighbor)

    return path

def find_maximum_route(n, m, flights):
    graph = defaultdict(list)

    for a, b in flights:
        graph[a].append(b)

    visited = [False] * (n + 1)
    route = dfs(graph, visited, 1)

    if route[-1] == n:
        return len(route), route
    else:
        return "IMPOSSIBLE"

# Read input
n, m = map(int, input().split())
flights = [tuple(map(int, input().split())) for _ in range(m)]

# Find maximum route
result = find_maximum_route(n, m, flights)

# Print result
if isinstance(result, tuple):
    print(result[0])
    print(" ".join(map(str, result[1])))
else:
    print(result)
