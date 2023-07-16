
MOD = int(1e9 + 7)

def count_paths(n, m, k, edges):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[1][0] = 1

    for j in range(1, k + 1):
        for u, v in edges:
            dp[v][j] = (dp[v][j] + dp[u][j - 1]) % MOD

    return dp[n][k]

# Read input
n, m, k = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

# Count paths
result = count_paths(n, m, k, edges)

# Print result
print(result)
