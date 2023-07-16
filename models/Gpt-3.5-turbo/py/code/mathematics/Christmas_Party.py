
n = int(input())

# Calculate derangements using dynamic programming
MOD = int(1e9) + 7
dp = [0] * (n + 1)
dp[1] = 0
dp[2] = 1
for i in range(3, n + 1):
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD

print(dp[n])
