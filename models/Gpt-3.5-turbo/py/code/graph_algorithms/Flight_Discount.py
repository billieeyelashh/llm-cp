
import heapq

def dijkstra(n, m, flights):
    adj_list = [[] for _ in range(n)]
    for a, b, c in flights:
        adj_list[a-1].append((b-1, c))
    
    distance = [float('inf')] * n
    distance[0] = 0
    
    pq = [(0, 0)]  # (distance, city)
    while pq:
        dist, city = heapq.heappop(pq)
        
        if city == n-1:
            break
        
        if dist > distance[city]:
            continue
        
        for neighbor, price in adj_list[city]:
            new_dist = dist + price
            new_dist_half = dist + (price // 2)
            
            if new_dist < distance[neighbor]:
                distance[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))
            
            if new_dist_half < distance[neighbor]:
                distance[neighbor] = new_dist_half
                heapq.heappush(pq, (new_dist_half, neighbor))
    
    return distance[n-1]

# Read input
n, m = map(int, input().split())
flights = []
for _ in range(m):
    a, b, c = map(int, input().split())
    flights.append((a, b, c))

# Run Dijkstra's algorithm
result = dijkstra(n, m, flights)

# Print the result
print(result)
