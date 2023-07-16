
# Read input
n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

paths = [0] * (n+1)

def dfs(node, visited):
    visited[node] = True
    paths[node] += 1
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited)
            paths[node] += paths[neighbor]

# Perform DFS for each path
for _ in range(m):
    a, b = map(int, input().split())
    visited = [False] * (n+1)
    dfs(a, visited)
    dfs(b, visited)

# Print output
print(" ".join(str(paths[i]) for i in range(1, n+1)))
