
def find_round_trip(n, m, roads):
    # Step 1: Create adjacency list
    graph = [[] for _ in range(n + 1)]
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)

    # Step 2: Initialize visited array
    visited = [False] * (n + 1)

    # Step 3: Start DFS from each city
    for city in range(1, n + 1):
        if not visited[city]:
            path = dfs(city, city, graph, visited)
            if path:
                return path

    return "IMPOSSIBLE"

def dfs(start, city, graph, visited):
    # Step 4: Mark current city as visited and add to path
    visited[city] = True
    path = [city]

    # Step 5: Iterate through neighbors
    for neighbor in graph[city]:
        # Step 6: If neighbor is visited and not start city, return path
        if visited[neighbor] and neighbor != start:
            return path

        # Recursive call for unvisited neighbors
        if not visited[neighbor]:
            path += dfs(start, neighbor, graph, visited)

            # Step 6: If cycle found, return path
            if path[-1] == start:
                return path

    return []

# Read input
n, m = map(int, input().split())
roads = []
for _ in range(m):
    a, b = map(int, input().split())
    roads.append((a, b))

# Call the function and print the result
result = find_round_trip(n, m, roads)
if result == "IMPOSSIBLE":
    print(result)
else:
    print(len(result))
    print(" ".join(map(str, result)))
