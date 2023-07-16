
def dfs(city, graph, visited):
    visited[city] = True
    for neighbor in graph[city]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited)

def find_round_trip(n, m, flights):
    # Create an adjacency list to represent the flights
    graph = [[] for _ in range(n+1)]
    for a, b in flights:
        graph[a].append(b)

    # Initialize visited array
    visited = [False] * (n+1)

    # Start DFS from each city
    for city in range(1, n+1):
        if not visited[city]:
            dfs(city, graph, visited)
            # Check if a round trip is found
            if all(visited[1:]):
                return [city] + [i for i in range(1, n+1) if graph[i]]

    return "IMPOSSIBLE"

# Read input
n, m = map(int, input().split())
flights = [list(map(int, input().split())) for _ in range(m)]

# Find and print the round trip
result = find_round_trip(n, m, flights)
if result == "IMPOSSIBLE":
    print(result)
else:
    print(len(result))
    print(*result)
