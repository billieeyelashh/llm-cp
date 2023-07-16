
n = int(input())
dp = [0] * (n+1)
dp[1] = 0

for i in range(2, n+1):
    dp[i] = dp[i-2] + 4 * sum(dp[j] for j in range(i-1))

for i in range(1, n+1):
    print(dp[i])
