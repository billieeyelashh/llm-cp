
MOD = 10**9+7

def count_paths(n, m, traps):
    dp = [[0] * (n+1) for _ in range(n+1)]
    dp[1][1] = 1

    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i, j) in traps:
                dp[i][j] = 0
            else:
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD

    return dp[n][n]

# Read input
n, m = map(int, input().split())
traps = [tuple(map(int, input().split())) for _ in range(m)]

# Compute and print the answer
print(count_paths(n, m, traps))
