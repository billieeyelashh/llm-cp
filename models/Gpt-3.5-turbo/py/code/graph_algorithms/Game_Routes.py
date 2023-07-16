
MOD = int(1e9) + 7

n, m = map(int, input().split())

dp = [0] * (n+1)
dp[1] = 1

for _ in range(m):
    a, b = map(int, input().split())
    dp[b] += dp[a]
    dp[b] %= MOD

print(dp[n] % MOD)
