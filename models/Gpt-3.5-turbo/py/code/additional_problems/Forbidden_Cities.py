
from collections import defaultdict, deque

def has_route_without_city(n, m, q, roads, queries):
    # Create an adjacency list representation of the graph
    graph = defaultdict(list)
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)

    # Process each query
    for a, b, c in queries:
        # Perform BFS starting from city a
        visited = [False] * (n + 1)
        queue = deque([a])
        visited[a] = True

        while queue:
            current_city = queue.popleft()

            # If the current city is the destination city, return "YES"
            if current_city == b:
                print("YES")
                break

            # Explore neighboring cities
            for neighbor in graph[current_city]:
                # Skip the forbidden city
                if neighbor == c:
                    continue

                # Visit unvisited neighboring cities
                if not visited[neighbor]:
                    queue.append(neighbor)
                    visited[neighbor] = True
        else:  # If BFS completes without reaching the destination, return "NO"
            print("NO")

# Read input
n, m, q = map(int, input().split())
roads = [list(map(int, input().split())) for _ in range(m)]
queries = [list(map(int, input().split())) for _ in range(q)]

# Solve the problem
has_route_without_city(n, m, q, roads, queries)
