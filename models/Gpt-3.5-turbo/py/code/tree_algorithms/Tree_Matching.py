
n = int(input())
adj = {i: [] for i in range(1, n+1)}

for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def dfs(node, include):
    count = 0
    for neighbor in adj[node]:
        if (not include) or (neighbor not in matching):
            count += dfs(neighbor, not include)
    return count + include

matching = set()
result = dfs(1, False)
print(result)
