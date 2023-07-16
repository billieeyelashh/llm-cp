
import heapq

def dijkstra(n, m, flights):
    # Initialize the data structures
    costs = [float('inf')] * n
    routes = [0] * n
    min_flights = [float('inf')] * n
    max_flights = [0] * n
    graph = [[] for _ in range(n)]

    # Build the adjacency list representation of the graph
    for a, b, c in flights:
        graph[a-1].append((b-1, c))

    # Dijkstra's algorithm
    queue = [(0, 0)]  # (cost, city)
    costs[0] = 0
    routes[0] = 1
    min_flights[0] = 0
    max_flights[0] = 0

    while queue:
        cost, city = heapq.heappop(queue)

        if cost > costs[city]:
            continue

        for neighbor, flight_cost in graph[city]:
            new_cost = cost + flight_cost

            if new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                routes[neighbor] = routes[city]
                min_flights[neighbor] = min_flights[city] + 1
                max_flights[neighbor] = max_flights[city] + 1
                heapq.heappush(queue, (new_cost, neighbor))
            elif new_cost == costs[neighbor]:
                routes[neighbor] = (routes[neighbor] + routes[city]) % (10**9 + 7)
                min_flights[neighbor] = min(min_flights[neighbor], min_flights[city] + 1)
                max_flights[neighbor] = max(max_flights[neighbor], max_flights[city] + 1)

    return costs[n-1], routes[n-1], min_flights[n-1], max_flights[n-1]

# Read the input
n, m = map(int, input().split())
flights = [list(map(int, input().split())) for _ in range(m)]

# Call the dijkstra function and print the results
min_price, num_routes, min_num_flights, max_num_flights = dijkstra(n, m, flights)
print(min_price, num_routes, min_num_flights, max_num_flights)
