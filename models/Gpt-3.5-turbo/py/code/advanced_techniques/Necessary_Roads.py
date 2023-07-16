
# Function to perform Depth First Search (DFS) on the graph
def dfs(node, graph, visited, stack):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, stack)
    stack.append(node)

# Function to perform Reverse Depth First Search (DFS) on the transposed graph
def reverse_dfs(node, transposed_graph, visited, scc):
    visited[node] = True
    scc.append(node)
    for neighbor in transposed_graph[node]:
        if not visited[neighbor]:
            reverse_dfs(neighbor, transposed_graph, visited, scc)

# Function to find all Strongly Connected Components (SCCs) in the graph
def find_scc(graph, transposed_graph, n):
    visited = [False] * (n + 1)
    stack = []
    # Perform DFS on the graph and push nodes onto stack in order of finishing time
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i, graph, visited, stack)
    
    visited = [False] * (n + 1)
    sccs = []
    # Perform Reverse DFS on the transposed graph to find SCCs
    while stack:
        node = stack.pop()
        if not visited[node]:
            scc = []
            reverse_dfs(node, transposed_graph, visited, scc)
            sccs.append(scc)
    
    return sccs

# Function to find necessary roads in the graph
def find_necessary_roads(n, m, roads):
    # Build adjacency list representation of the graph
    graph = [[] for _ in range(n + 1)]
    transposed_graph = [[] for _ in range(n + 1)]
    for road in roads:
        a, b = road
        graph[a].append(b)
        transposed_graph[b].append(a)
    
    # Find all Strongly Connected Components (SCCs) in the graph
    sccs = find_scc(graph, transposed_graph, n)
    
    necessary_roads = []
    # Check for SCCs with only one outgoing edge
    for scc in sccs:
        outgoing_edges = set()
        for node in scc:
            for neighbor in graph[node]:
                if neighbor not in scc:
                    outgoing_edges.add(neighbor)
        if len(outgoing_edges) == 1:
            necessary_roads.append(outgoing_edges.pop())
    
    return necessary_roads

# Read input
n, m = map(int, input().split())
roads = []
for _ in range(m):
    a, b = map(int, input().split())
    roads.append((a, b))

# Find necessary roads
necessary_roads = find_necessary_roads(n, m, roads)

# Print number of necessary roads and the necessary roads themselves
print(len(necessary_roads))
for road in necessary_roads:
    print(road)
