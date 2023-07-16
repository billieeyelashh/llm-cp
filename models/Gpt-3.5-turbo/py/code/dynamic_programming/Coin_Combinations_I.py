
MOD = int(1e9) + 7

n, x = map(int, input().split())
coins = list(map(int, input().split()))

dp = [[0] * (x+1) for _ in range(n+1)]
dp[0][0] = 1

for i in range(1, n+1):
    for j in range(x+1):
        dp[i][j] = dp[i-1][j]
        if j >= coins[i-1]:
            dp[i][j] += dp[i][j-coins[i-1]]
        dp[i][j] %= MOD

print(dp[n][x])
