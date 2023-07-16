
MOD = int(1e9) + 7

def countEulerianSubgraphs(n, m, edges):
    # Initialize the dp table
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # Calculate the degree of each node
    degrees = [0] * (n + 1)
    for a, b in edges:
        degrees[a] += 1
        degrees[b] += 1

    # Calculate the dp table
    for v in range(1, n + 1):
        if degrees[v] % 2 == 0:
            dp[v][0] = 1

    for v in range(1, n + 1):
        for d in range(1, n + 1):
            for u in edges[v]:
                for i in range(d + 1):
                    dp[v][d] += dp[u][i] * dp[v][d - i] % MOD
                    dp[v][d] %= MOD

    # Calculate the final result
    result = 0
    for v in range(1, n + 1):
        if degrees[v] % 2 == 0:
            result += dp[v][degrees[v]]
            result %= MOD

    return result

# Read the input
n, m = map(int, input().split())
edges = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

# Calculate and print the result
result = countEulerianSubgraphs(n, m, edges)
print(result)
