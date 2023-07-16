
import heapq

def minimum_price_route(n, m, flights):
    # Create an adjacency list to represent the flights
    adj = [[] for _ in range(n + 1)]
    for a, b, c in flights:
        adj[a].append((b, c))

    # Initialize the distances and the previous cities
    dist = [float('inf')] * (n + 1)
    prev = [-1] * (n + 1)

    # Start from Syrjälä
    dist[1] = 0
    pq = [(0, 1, -1)]

    while pq:
        price, city, prev_city = heapq.heappop(pq)

        # Ignore the city if we have already found a cheaper path
        if price > dist[city]:
            continue

        # Update the minimum price and previous city for each neighbor
        for neighbor, neighbor_price in adj[city]:
            new_price = price + neighbor_price
            if new_price < dist[neighbor]:
                dist[neighbor] = new_price
                prev[neighbor] = city
                heapq.heappush(pq, (new_price, neighbor, city))

    # Reconstruct the path from Lehmälä to Syrjälä
    path = []
    current_city = n
    while current_city != -1:
        path.append(current_city)
        current_city = prev[current_city]
    path.reverse()

    return len(path), path

# Read the input
n, m = map(int, input().split())
flights = [list(map(int, input().split())) for _ in range(m)]

# Find the minimum-price route
k, cities = minimum_price_route(n, m, flights)

# Print the output
print(k)
print(*cities)
