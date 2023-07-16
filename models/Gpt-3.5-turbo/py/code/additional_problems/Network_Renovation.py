
from collections import defaultdict

def add_connections(n, connections):
    graph = defaultdict(list)
    
    # Build the graph
    for a, b in connections:
        graph[a].append(b)
        graph[b].append(a)
    
    # Perform DFS to find unconnected nodes
    visited = [False] * (n + 1)
    unconnected = []
    
    def dfs(node):
        visited[node] = True
        
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
    
    dfs(1)  # Start DFS from any node
    
    for i in range(1, n + 1):
        if not visited[i]:
            unconnected.append(i)
    
    # Add new connections between unconnected nodes
    k = len(unconnected)
    new_connections = []
    
    for i in range(k - 1):
        new_connections.append((unconnected[i], unconnected[i + 1]))
    
    return k, new_connections

# Read input
n = int(input())
connections = []
for _ in range(n - 1):
    a, b = map(int, input().split())
    connections.append((a, b))

# Call the function and print the result
k, new_connections = add_connections(n, connections)
print(k)
for a, b in new_connections:
    print(a, b)
