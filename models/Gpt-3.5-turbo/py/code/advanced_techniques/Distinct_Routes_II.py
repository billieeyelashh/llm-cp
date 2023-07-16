
import sys

n, m, k = map(int, input().split())

# Initialize the dp table
INF = sys.maxsize
dp = [[[INF] * (k+1) for _ in range(m+1)] for _ in range(n+1)]
dp[1][0][0] = 0

# Read teleporters
teleporters = []
for _ in range(m):
    a, b = map(int, input().split())
    teleporters.append((a, b))

# Dynamic programming
for j in range(1, k+1):
    for i in range(1, n+1):
        for a, b in teleporters:
            if b == i:
                for x in range(k-1, -1, -1):
                    dp[i][j][x+1] = min(dp[i][j][x+1], dp[a][j-1][x] + 1)

# Find the minimum number of coins required on the last day
min_coins = min(dp[n][k])

# If it is not possible to play the game for k days, print -1
if min_coins == INF:
    print(-1)
else:
    print(min_coins)

# Print the routes for each day
for j in range(1, k+1):
    for i in range(1, n+1):
        for a, b in teleporters:
            if b == i and dp[i][j][k] == dp[a][j-1][k-1] + 1:
                print(a, end=' ')
                break
    print(n)
