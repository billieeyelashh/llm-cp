
n, x = map(int, input().split())
t = list(map(int, input().split()))

dp = [[0] * (x + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(x + 1):
        dp[i][j] = dp[i-1][j]
        if t[i-1] <= j:
            dp[i][j] += dp[i-1][j - t[i-1]]

print(dp[n][x])
