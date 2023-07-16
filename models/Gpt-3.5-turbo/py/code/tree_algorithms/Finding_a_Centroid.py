
def dfs(u, p, subtree_sizes, n):
    size = 1
    is_centroid = True

    for v in graph[u]:
        if v != p:
            dfs(v, u, subtree_sizes, n)
            size += subtree_sizes[v]
            if subtree_sizes[v] > n // 2:
                is_centroid = False

    subtree_sizes[u] = size

    if n - size > n // 2:
        is_centroid = False

    if is_centroid:
        centroids.append(u)

n = int(input())
graph = [[] for _ in range(n+1)]
subtree_sizes = [0] * (n+1)
centroids = []

for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(1, 0, subtree_sizes, n)

print(centroids[0])
