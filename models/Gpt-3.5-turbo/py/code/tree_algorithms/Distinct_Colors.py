
def dfs(v, parent):
    distinct_colors = set()

    for u in adj_list[v]:
        if u != parent:
            dfs(u, v)
            distinct_colors.update(distinct_colors_subtree[u])

    distinct_colors.add(colors[v])
    distinct_colors_subtree[v] = distinct_colors

# Read input
n = int(input())
colors = list(map(int, input().split()))

# Create adjacency list
adj_list = {i: [] for i in range(1, n+1)}
for _ in range(n-1):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

# Initialize distinct_colors_subtree list
distinct_colors_subtree = [set() for _ in range(n+1)]

# Perform DFS from the root node
dfs(1, 0)

# Print the number of distinct colors for each node
for i in range(1, n+1):
    print(len(distinct_colors_subtree[i]), end=" ")
