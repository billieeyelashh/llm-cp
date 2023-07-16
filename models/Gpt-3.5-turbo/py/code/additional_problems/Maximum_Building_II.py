
# Read input
n, m = map(int, input().split())
forest = [input() for _ in range(n)]

# Initialize dp array
dp = [[0] * (m+1) for _ in range(n+1)]
dp[0][1:] = [1] * m
for i in range(1, n+1):
    dp[i][0] = 1

# Calculate dp array
for i in range(1, n+1):
    for j in range(1, m+1):
        if forest[i-1][j-1] == '.':
            dp[i][j] = sum(dp[x][j-1] for x in range(i+1))

# Print dp array
for i in range(1, n+1):
    print(' '.join(map(str, dp[i][1:])))
