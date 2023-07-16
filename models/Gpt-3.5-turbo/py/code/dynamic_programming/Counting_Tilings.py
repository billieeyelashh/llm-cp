
MOD = int(1e9 + 7)

def count_ways(n, m):
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # Base cases
    dp[1][1] = 1
    dp[1][2] = 1
    dp[2][1] = 1
    dp[2][2] = 2

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i != 1 or j != 1:  # Skip base cases
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD

    return dp[n][m]

# Read input
n, m = map(int, input().split())

# Calculate and print the number of ways
print(count_ways(n, m))
