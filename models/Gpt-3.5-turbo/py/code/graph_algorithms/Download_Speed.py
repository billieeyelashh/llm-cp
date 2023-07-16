
import heapq

def maximum_speed(n, m, connections):
    # Create an adjacency list to represent the graph
    graph = [[] for _ in range(n+1)]
    for a, b, c in connections:
        graph[a].append((b, c))
        graph[b].append((a, c))

    # Initialize the MST set and visited array
    mst = [False] * (n+1)
    mst[1] = True
    visited = [False] * (n+1)

    # Use a priority queue to store the edges
    pq = []
    for b, c in graph[1]:
        heapq.heappush(pq, (c, b))

    total_speed = 0

    # Run Prim's algorithm
    while pq:
        c, b = heapq.heappop(pq)
        if visited[b]:
            continue

        # Mark the vertex as visited and add its speed to the total
        visited[b] = True
        total_speed += c

        # Add the new connections to the priority queue
        for d, speed in graph[b]:
            if not visited[d]:
                heapq.heappush(pq, (speed, d))

    return total_speed

# Read the input
n, m = map(int, input().split())
connections = [tuple(map(int, input().split())) for _ in range(m)]

# Calculate the maximum speed
max_speed = maximum_speed(n, m, connections)

# Print the result
print(max_speed)
