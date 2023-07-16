
from collections import defaultdict

def dfs(node, parent, adj_list, distances, subtree_sizes):
    distance = 0
    subtree_size = 1

    for neighbor in adj_list[node]:
        if neighbor == parent:
            continue
        dfs(neighbor, node, adj_list, distances, subtree_sizes)
        distance += distances[neighbor] + subtree_sizes[neighbor]
        subtree_size += subtree_sizes[neighbor]

    distances[node] = distance
    subtree_sizes[node] = subtree_size

def sum_of_distances(n, edges):
    adj_list = defaultdict(list)
    for a, b in edges:
        adj_list[a].append(b)
        adj_list[b].append(a)

    distances = [0] * (n + 1)
    subtree_sizes = [0] * (n + 1)

    dfs(1, 0, adj_list, distances, subtree_sizes)

    return distances

# Read input
n = int(input())
edges = []
for _ in range(n-1):
    a, b = map(int, input().split())
    edges.append((a, b))

# Calculate and print the sum of distances for each node
distances = sum_of_distances(n, edges)
print(*distances[1:])  # Ignore the distance for the root node (1)
