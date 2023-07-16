
n = int(input())
grid = [list(map(int, input())) for _ in range(n)]

dp = [[0] * (n+1) for _ in range(n+1)]

count = 0
for i in range(1, n+1):
    for j in range(1, n+1):
        if grid[i-1][j-1] == 1:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            count += dp[i][j]

print(count)
