
n, a, b = map(int, input().split())

dp = [[0] * (6*n + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
    for j in range(1, 6*n + 1):
        for k in range(1, 7):
            if j - k >= 0:
                dp[i+1][j] += dp[i][j-k]

total_probability = sum(dp[n][a:b+1])
answer = total_probability / (6**n)

print(f"{answer:.6f}")
