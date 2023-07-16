
MOD = int(1e9+7)

def count_ways(n, k):
    dp = [[0] * (k+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1
    for i in range(1, n+1):
        for j in range(1, k+1):
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * (i-1)
            dp[i][j] %= MOD
    return dp[n][k]

# Read input
n, k = map(int, input().split())

# Calculate and print result
result = count_ways(n, k)
print(result)
