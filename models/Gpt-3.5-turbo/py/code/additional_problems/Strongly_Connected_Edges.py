
from collections import defaultdict

def find_strongly_connected_components(graph):
    n = len(graph)
    index = 0
    stack = []
    lowlink = [-1] * n
    on_stack = [False] * n
    components = []

    def dfs(node):
        nonlocal index
        lowlink[node] = index
        index += 1
        stack.append(node)
        on_stack[node] = True

        for neighbor in graph[node]:
            if lowlink[neighbor] == -1:
                dfs(neighbor)
                lowlink[node] = min(lowlink[node], lowlink[neighbor])
            elif on_stack[neighbor]:
                lowlink[node] = min(lowlink[node], lowlink[neighbor])

        if lowlink[node] == index - 1:
            component = []
            while True:
                top = stack.pop()
                on_stack[top] = False
                component.append(top)
                if top == node:
                    break
            components.append(component)

    for node in range(n):
        if lowlink[node] == -1:
            dfs(node)

    return components

def solve(n, m, edges):
    graph = defaultdict(list)
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)

    components = find_strongly_connected_components(graph)
    num_components = len(components)

    if num_components == 1:
        return [(a, b) for a, b in edges]

    new_graph = defaultdict(list)
    for i, component in enumerate(components):
        for node in component:
            new_graph[node] = i

    new_edges = set()
    for a, b in edges:
        if new_graph[a] != new_graph[b]:
            new_edges.add((new_graph[a], new_graph[b]))

    directed_graph = defaultdict(list)
    for a, b in new_edges:
        directed_graph[a].append(b)

    visited = [False] * num_components
    result = []

    def dfs(node):
        visited[node] = True
        for neighbor in directed_graph[node]:
            if not visited[neighbor]:
                result.append((components[node][0], components[neighbor][0]))
                dfs(neighbor)

    for node in range(num_components):
        if not visited[node]:
            dfs(node)

    return result

# Read input
n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

# Solve problem
result = solve(n, m, edges)

# Print output
if len(result) == m:
    for a, b in result:
        print(a, b)
else:
    print("IMPOSSIBLE")
