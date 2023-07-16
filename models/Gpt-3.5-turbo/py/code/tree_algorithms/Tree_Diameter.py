
n = int(input())
adj = {i: [] for i in range(1, n+1)}

for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def dfs(node, distance, visited):
    visited[node] = True
    max_distance = distance
    farthest_node = node

    for neighbor in adj[node]:
        if not visited[neighbor]:
            new_distance = distance + 1
            temp_distance, temp_node = dfs(neighbor, new_distance, visited)
            if temp_distance > max_distance:
                max_distance = temp_distance
                farthest_node = temp_node

    return max_distance, farthest_node

# Find the farthest node from any arbitrary starting node
start_node = 1
visited = {i: False for i in range(1, n+1)}
_, farthest_node = dfs(start_node, 0, visited)

# Find the diameter of the tree
visited = {i: False for i in range(1, n+1)}
diameter, _ = dfs(farthest_node, 0, visited)

print(diameter)
