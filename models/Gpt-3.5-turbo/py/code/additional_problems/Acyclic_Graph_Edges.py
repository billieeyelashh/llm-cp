
from collections import defaultdict

def dfs(node, graph, visited, ordering):
    visited[node] = True
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, ordering)
            
    ordering.insert(0, node)

def solve(n, m, edges):
    graph = defaultdict(list)
    
    for a, b in edges:
        graph[a].append(b)
        
    visited = [False] * (n+1)
    ordering = []
    
    for node in range(1, n+1):
        if not visited[node]:
            dfs(node, graph, visited, ordering)
            
    ordering.reverse()
    
    directions = []
    
    for node in ordering:
        for neighbor in graph[node]:
            directions.append((node, neighbor))
    
    return directions

# Read input
n, m = map(int, input().split())

edges = []
for _ in range(m):
    a, b = map(int, input().split())
    edges.append((a, b))

# Solve the problem
directions = solve(n, m, edges)

# Print the directions
for a, b in directions:
    print(a, b)
