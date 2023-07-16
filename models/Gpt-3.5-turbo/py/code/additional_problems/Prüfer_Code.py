
# Step 1
n = int(input())
prufer = list(map(int, input().split()))

# Step 2
tree = []

# Step 3
degree = [1] * (n+1)

# Step 4
for p in prufer:
    # Step 4a
    leaf = min(node for node in range(1, n+1) if degree[node] == 1)
    
    # Step 4b
    tree.append((leaf, p))
    
    # Step 4c
    degree[leaf] += 1
    degree[p] += 1

# Step 5
leaf1 = min(node for node in range(1, n+1) if degree[node] == 1)
leaf2 = min(node for node in range(1, n+1) if degree[node] == 1 and node != leaf1)
tree.append((leaf1, leaf2))

# Step 6
for edge in tree:
    print(edge[0], edge[1])
