
def solve(n, m, tunnels):
    dist = [float('-inf')] * n
    dist[0] = 0

    for _ in range(n-1):
        for a, b, x in tunnels:
            if dist[a-1] + x > dist[b-1]:
                dist[b-1] = dist[a-1] + x
    
    for a, b, x in tunnels:
        if dist[a-1] + x > dist[b-1]:
            return -1

    return dist[n-1]

# Read input
n, m = map(int, input().split())
tunnels = []
for _ in range(m):
    a, b, x = map(int, input().split())
    tunnels.append((a, b, x))

# Solve and print the result
print(solve(n, m, tunnels))
