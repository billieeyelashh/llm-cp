
def dfs(node, graph, visited):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited)

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

visited = [False] * (n + 1)
dfs(1, graph, visited)

if all(visited[1:]):
    print("YES")
else:
    for city in range(1, n + 1):
        if not visited[city]:
            print("NO")
            print("1", city)
            break
