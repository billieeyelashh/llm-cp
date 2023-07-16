
import heapq

def cheapest_way(n, m, k, routes):
    # Create an adjacency list to represent the graph
    graph = [[] for _ in range(n + 1)]
    for a, b, r, c in routes:
        graph[a].append((b, r, c))

    # Create a priority queue to store the vertices to be processed
    pq = [(0, 1, 0)]  # (cost, vertex, parcels)
    heapq.heapify(pq)

    # Create a list to store the minimum cost to reach each vertex
    min_cost = [float('inf')] * (n + 1)
    min_cost[1] = 0

    while pq:
        cur_cost, cur_vertex, cur_parcels = heapq.heappop(pq)

        if cur_vertex == n and cur_parcels == k:
            return cur_cost

        for next_vertex, max_parcels, parcel_cost in graph[cur_vertex]:
            if cur_parcels + 1 <= k and cur_cost + parcel_cost < min_cost[next_vertex]:
                min_cost[next_vertex] = cur_cost + parcel_cost
                heapq.heappush(pq, (cur_cost + parcel_cost, next_vertex, cur_parcels + 1))

    return -1

# Read input
n, m, k = map(int, input().split())
routes = [list(map(int, input().split())) for _ in range(m)]

# Call the function and print the result
print(cheapest_way(n, m, k, routes))
