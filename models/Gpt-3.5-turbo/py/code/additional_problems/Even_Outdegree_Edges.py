
from collections import defaultdict

def solve(n, m, edges):
    graph = defaultdict(list)
    
    # Step 1: Create an empty directed graph
    for a, b in edges:
        graph[a].append(b)
    
    # Step 3: Check and modify outdegree
    outdegree = {node: len(neighbors) for node, neighbors in graph.items()}
    for node, degree in outdegree.items():
        if degree % 2 == 1:
            # Find another node with odd outdegree
            for other_node, other_degree in outdegree.items():
                if other_degree % 2 == 1 and other_node != node:
                    # Add an additional edge
                    graph[other_node].append(node)
                    outdegree[other_node] += 1
                    outdegree[node] += 1
                    break
            else:
                # No valid solution
                return "IMPOSSIBLE"
    
    # Step 5: Print the directed graph
    directed_edges = [(a, b) for a, neighbors in graph.items() for b in neighbors]
    return directed_edges

# Read input
n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

# Solve the problem
result = solve(n, m, edges)

# Print the result
if result == "IMPOSSIBLE":
    print("IMPOSSIBLE")
else:
    for a, b in result:
        print(a, b)
