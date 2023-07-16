
n, k_1, k_2 = map(int, input().split())

# Create adjacency list representation of the tree
adj_list = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

count = 0

def dfs(cur, prev, length):
    global count

    if k_1 <= length <= k_2:
        count += 1

    for next in adj_list[cur]:
        if next != prev:
            dfs(next, cur, length + 1)

# Start the DFS traversal from an arbitrary node (e.g., node 1)
dfs(1, 0, 0)

print(count)
