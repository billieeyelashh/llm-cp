
def dfs(node, visited, graph, route):
    visited[node] = True
    route.append(node)

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited, graph, route)

    return route

def find_route(n, m, streets):
    # Initialize the graph as an adjacency list
    graph = [[] for _ in range(n + 1)]  # +1 for 1-based indexing

    # Build the graph from the input streets
    for a, b in streets:
        graph[a].append(b)
        graph[b].append(a)

    # Initialize visited array
    visited = [False] * (n + 1)

    # Start the DFS from the post office (node 1)
    route = dfs(1, visited, graph, [])

    # If not all crossings were visited, it's impossible to find a valid route
    if len(route) != n:
        return "IMPOSSIBLE"

    # Otherwise, return the route as a space-separated string
    return ' '.join(map(str, route))

# Read input
n, m = map(int, input().split())
streets = [tuple(map(int, input().split())) for _ in range(m)]

# Find and print the route
print(find_route(n, m, streets))
