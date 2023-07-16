
def dfs(node, adj_list, visited, path_length, k, path_count):
    visited[node] = True

    # Check if the current path length matches k
    if path_length == k:
        path_count[0] += 1

    # Continue DFS on adjacent nodes
    for neighbor in adj_list[node]:
        if not visited[neighbor]:
            dfs(neighbor, adj_list, visited, path_length + 1, k, path_count)

    visited[node] = False

n, k = map(int, input().split())
adj_list = [[] for _ in range(n+1)]

# Build adjacency list
for _ in range(n-1):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

# Initialize variables
visited = [False] * (n+1)
path_count = [0]

# Start DFS from each node
for node in range(1, n+1):
    dfs(node, adj_list, visited, 0, k, path_count)

print(path_count[0])
