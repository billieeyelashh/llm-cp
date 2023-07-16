
def find_negative_cycle(n, m, edges):
    dist = [float('inf')] * (n + 1)
    parent = [-1] * (n + 1)
    cycle = []

    # Step 1: Set the distance of the source node to 0
    dist[1] = 0

    # Step 2: Relax each edge for n-1 times
    for _ in range(n - 1):
        for a, b, c in edges:
            if dist[a] + c < dist[b]:
                dist[b] = dist[a] + c
                parent[b] = a

    # Step 3: Check for negative cycles
    for a, b, c in edges:
        if dist[a] + c < dist[b]:
            # Step 4: Find negative cycle
            x = b
            for _ in range(n):
                x = parent[x]
            y = x
            while True:
                cycle.append(y)
                if y == x and len(cycle) > 1:
                    break
                y = parent[y]
            cycle.reverse()
            return "YES", cycle

    # Step 5: No negative cycle found
    return "NO"

# Read input
n, m = map(int, input().split())
edges = []
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

# Find negative cycle
result = find_negative_cycle(n, m, edges)

# Print output
print(result[0])
if result[0] == "YES":
    print(' '.join(map(str, result[1])))
