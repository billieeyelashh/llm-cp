
import sys
sys.setrecursionlimit(2*10**5)  # Set recursion limit to avoid stack overflow

def tarjan_scc(graph):
    n = len(graph)
    index = 0
    stack = []
    on_stack = [False] * n
    lowlink = [-1] * n
    index = [-1] * n
    sccs = []

    def strongconnect(node):
        nonlocal index
        index[node] = index
        lowlink[node] = index
        index += 1
        stack.append(node)
        on_stack[node] = True

        for neighbor in graph[node]:
            if index[neighbor] == -1:
                strongconnect(neighbor)
                lowlink[node] = min(lowlink[node], lowlink[neighbor])
            elif on_stack[neighbor]:
                lowlink[node] = min(lowlink[node], index[neighbor])

        if lowlink[node] == index[node]:
            scc = []
            while True:
                scc_node = stack.pop()
                on_stack[scc_node] = False
                scc.append(scc_node)
                if scc_node == node:
                    break
            sccs.append(scc)

    for node in range(n):
        if index[node] == -1:
            strongconnect(node)

    return sccs

# Read the input
n, m = map(int, input().split())

# Create an empty adjacency list
graph = [[] for _ in range(n)]

# Read the requests and update the adjacency list
for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)

# Find all SCCs
sccs = tarjan_scc(graph)

# Count the number of SCCs with more than one node
count = sum(len(scc) > 1 for scc in sccs)

# Print the result
print(count)
