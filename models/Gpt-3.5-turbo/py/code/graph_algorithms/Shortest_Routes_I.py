
import heapq

def dijkstra(n, m, connections):
    dist = [float('inf')] * n
    dist[0] = 0

    pq = [(0, 0)]

    while pq:
        d, u = heapq.heappop(pq)

        if d > dist[u]:
            continue

        for v, w in connections[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist

# Read input
n, m = map(int, input().split())
connections = [[] for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    connections[a-1].append((b-1, c))

# Run Dijkstra's algorithm
distances = dijkstra(n, m, connections)

# Print the shortest route lengths from Syrjälä to each city
print(*distances)
