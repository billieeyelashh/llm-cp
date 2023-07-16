
def dfs(node, parent, adj_list, max_distance):
    max_distance[node] = 0
    
    for neighbor in adj_list[node]:
        if neighbor != parent:
            max_distance[node] = max(max_distance[node], dfs(neighbor, node, adj_list, max_distance) + 1)
    
    return max_distance[node]

def solve(n, edges):
    adj_list = [[] for _ in range(n + 1)]
    max_distance = [0] * (n + 1)

    for a, b in edges:
        adj_list[a].append(b)
        adj_list[b].append(a)

    dfs(1, 0, adj_list, max_distance)

    return max_distance[1:]

# Read input
n = int(input())
edges = []
for _ in range(n-1):
    a, b = map(int, input().split())
    edges.append((a, b))

# Solve the problem
result = solve(n, edges)

# Print the result
print(' '.join(map(str, result)))
