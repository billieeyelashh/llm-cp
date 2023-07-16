
n, q = map(int, input().split())
values = list(map(int, input().split()))

adj_list = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    adj_list[a - 1].append(b - 1)
    adj_list[b - 1].append(a - 1)

subtree_sum = [0] * n

def dfs(v):
    subtree_sum[v] = values[v]
    for neighbor in adj_list[v]:
        if subtree_sum[neighbor] == 0:
            dfs(neighbor)
        subtree_sum[v] += subtree_sum[neighbor]

dfs(0)

for _ in range(q):
    query = input().split()
    if query[0] == '1':
        s, x = map(int, query[1:])
        values[s - 1] = x
    elif query[0] == '2':
        s = int(query[1])
        print(subtree_sum[s - 1])
