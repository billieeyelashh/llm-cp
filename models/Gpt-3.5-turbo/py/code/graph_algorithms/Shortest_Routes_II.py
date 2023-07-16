
import heapq
from collections import defaultdict

def dijkstra(graph, n, source):
    distances = [float('inf')] * (n + 1)
    distances[source] = 0
    heap = [(0, source)]
    
    while heap:
        dist, node = heapq.heappop(heap)
        
        if dist > distances[node]:
            continue
        
        for neighbor, weight in graph[node]:
            new_dist = dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(heap, (new_dist, neighbor))
    
    return distances

# Read input
n, m, q = map(int, input().split())

# Create adjacency list
graph = defaultdict(list)
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

# Process queries
for _ in range(q):
    a, b = map(int, input().split())
    
    # Run Dijkstra's algorithm
    distances = dijkstra(graph, n, a)
    
    # Print shortest path distance or -1 if no path exists
    if distances[b] == float('inf'):
        print(-1)
    else:
        print(distances[b])
