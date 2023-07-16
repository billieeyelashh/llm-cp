
MOD = int(1e9+7)

n, m = map(int, input().split())
traps = [tuple(map(int, input().split())) for _ in range(m)]

dp = [[0] * n for _ in range(n)]
dp[0][0] = 1

for i in range(n):
    for j in range(n):
        if (i+1, j+1) not in traps:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD

print(dp[n-1][n-1])
