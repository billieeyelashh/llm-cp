
def dfs(node, graph, visited, reachable):
    visited[node] = True
    reachable[node] += 1

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, reachable)

n, m = map(int, input().split())

graph = {i: [] for i in range(1, n+1)}

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

reachable = [0] * (n+1)
visited = [False] * (n+1)

for node in range(1, n+1):
    if not visited[node]:
        dfs(node, graph, visited, reachable)

print(' '.join(map(str, reachable[1:])))
