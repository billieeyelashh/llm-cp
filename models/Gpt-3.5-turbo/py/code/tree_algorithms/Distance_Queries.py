
def dfs(node, parent, depth, adj_list):
    distance[node] = depth
    for neighbor in adj_list[node]:
        if neighbor != parent:
            dfs(neighbor, node, depth + 1, adj_list)

# Read input
n, q = map(int, input().split())

# Create adjacency list
adj_list = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

# Process queries
for _ in range(q):
    a, b = map(int, input().split())

    # Initialize distance array for each query
    distance = [0] * (n + 1)
    
    # Perform DFS traversal from node 'a'
    dfs(a, 0, 0, adj_list)
    
    # Print the distance between 'a' and 'b'
    print(distance[b])
