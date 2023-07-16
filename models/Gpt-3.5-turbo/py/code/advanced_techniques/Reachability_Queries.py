
# Read input values
n, m, q = map(int, input().split())

# Create an empty adjacency list
adj_list = {}

# Read the edges and populate the adjacency list
for _ in range(m):
    a, b = map(int, input().split())
    if a in adj_list:
        adj_list[a].append(b)
    else:
        adj_list[a] = [b]

# Define the DFS function
def dfs(start, target):
    visited = set()
    stack = [start]

    while stack:
        node = stack.pop()

        if node == target:
            return "YES"

        if node not in visited:
            visited.add(node)
            if node in adj_list:
                stack.extend(adj_list[node])

    return "NO"

# Process the queries
for _ in range(q):
    a, b = map(int, input().split())
    print(dfs(a, b))
