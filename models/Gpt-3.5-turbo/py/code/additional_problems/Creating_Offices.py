
from collections import defaultdict

def dfs(node, parent, graph, distance, max_distance):
    distance[node] = distance[parent] + 1
    max_distance[0] = max(max_distance[0], distance[node])
    
    for neighbor in graph[node]:
        if neighbor != parent:
            dfs(neighbor, node, graph, distance, max_distance)

def solve(n, d, roads):
    graph = defaultdict(list)
    for u, v in roads:
        graph[u].append(v)
        graph[v].append(u)
    
    distance = [0] * (n+1)
    max_distance = [0]
    
    dfs(1, 0, graph, distance, max_distance)
    
    if max_distance[0] <= d:
        return (n, range(1, n+1))
    
    max_node = distance.index(max(distance))
    
    distance = [0] * (n+1)
    max_distance = [0]
    
    dfs(max_node, 0, graph, distance, max_distance)
    
    offices = [i for i in range(1, n+1) if distance[i] >= d]
    return (len(offices), offices)

# Read input
n, d = map(int, input().split())
roads = [list(map(int, input().split())) for _ in range(n-1)]

# Solve the problem
result = solve(n, d, roads)

# Print the result
print(result[0])
print(*result[1])
