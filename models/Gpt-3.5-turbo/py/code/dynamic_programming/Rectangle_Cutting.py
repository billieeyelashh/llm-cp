
a, b = map(int, input().split())

# Initialize dp array
dp = [[0] * (b+1) for _ in range(a+1)]

# Base case
dp[1][1] = 0

# Iterate over rows and columns
for i in range(1, a+1):
    for j in range(1, b+1):
        if i == j:
            dp[i][j] = 0
        else:
            # Find minimum number of moves
            dp[i][j] = float('inf')
            for k in range(1, i//2 + 1):
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1)
            for k in range(1, j//2 + 1):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1)

# Print the minimum number of moves
print(dp[a][b])
