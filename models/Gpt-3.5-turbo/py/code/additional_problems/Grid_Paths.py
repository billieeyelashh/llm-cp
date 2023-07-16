
n, m = map(int, input().split())
traps = [list(map(int, input().split())) for _ in range(m)]

mod = 10**9 + 7

dp = [[0] * (n+1) for _ in range(n+1)]
dp[1][1] = 1

for i in range(1, n+1):
    for j in range(1, n+1):
        if [i,j] in traps:
            dp[i][j] = 0
        else:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod

print(dp[n][n])
