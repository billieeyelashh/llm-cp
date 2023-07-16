
MOD = int(1e9) + 7

n, m = map(int, input().split())
x = list(map(int, input().split()))

dp = [[0] * (m+2) for _ in range(n+1)]
dp[1][1:m+1] = [1] * m

for i in range(2, n+1):
    if x[i-1] == 0:
        for j in range(1, m+1):
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD
    else:
        j = x[i-1]
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD

answer = sum(dp[n]) % MOD
print(answer)
