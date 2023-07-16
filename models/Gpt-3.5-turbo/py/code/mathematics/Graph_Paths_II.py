
import heapq

def shortest_path(graph, start, end, k):
    # Initialize distances to infinity except for the starting node
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # Initialize a priority queue with the starting node and its distance
    queue = [(0, start, 0)]

    # Run Dijkstra's algorithm
    while queue:
        dist, node, edges = heapq.heappop(queue)

        # If the current node is the end node with exactly k edges, return the distance
        if node == end and edges == k:
            return dist

        # Stop processing if we have already visited the current node with fewer edges
        if dist > distances[node]:
            continue

        # Explore neighbors
        for neighbor, weight in graph[node]:
            # If the number of edges is less than k, add the edge to the priority queue
            if edges < k:
                new_dist = dist + weight
                new_edges = edges + 1
                if new_dist < distances[neighbor]:
                    distances[neighbor] = new_dist
                    heapq.heappush(queue, (new_dist, neighbor, new_edges))

    # If there is no path from start to end with exactly k edges, return -1
    return -1

# Read input
n, m, k = map(int, input().split())

# Create an adjacency list representation of the graph
graph = {i: [] for i in range(1, n+1)}
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

# Print the minimum path length
print(shortest_path(graph, 1, n, k))
