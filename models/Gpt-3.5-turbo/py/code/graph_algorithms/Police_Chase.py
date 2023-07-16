
from collections import deque

def find_connected_crossings(n, m, streets):
    graph = [[] for _ in range(n)]
    for a, b in streets:
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    
    visited = [False] * n
    visited[0] = True
    queue = deque([0])
    connected_crossings = set()
    
    while queue:
        crossing = queue.popleft()
        connected_crossings.add(crossing)
        
        for neighbor in graph[crossing]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
    
    return connected_crossings

def find_minimum_streets(n, m, streets):
    connected_crossings = find_connected_crossings(n, m, streets)
    disconnected_streets = []
    
    for a, b in streets:
        if a-1 not in connected_crossings or b-1 not in connected_crossings:
            disconnected_streets.append((a, b))
    
    return disconnected_streets

# Read inputs
n, m = map(int, input().split())
streets = [tuple(map(int, input().split())) for _ in range(m)]

# Find minimum streets
disconnected_streets = find_minimum_streets(n, m, streets)

# Print the result
print(len(disconnected_streets))
for a, b in disconnected_streets:
    print(a, b)
