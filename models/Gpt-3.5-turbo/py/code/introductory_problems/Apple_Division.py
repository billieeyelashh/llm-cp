
n = int(input())
p = list(map(int, input().split()))

total_weight = sum(p)
half_weight = total_weight // 2

# Initialize the table
dp = [[float('inf')] * (half_weight + 1) for _ in range(n + 1)]
dp[0][0] = 0

for i in range(1, n + 1):
    for j in range(half_weight + 1):
        # Include the current apple
        if j >= p[i - 1]:
            dp[i][j] = min(dp[i][j], dp[i - 1][j - p[i - 1]])
        # Exclude the current apple
        dp[i][j] = min(dp[i][j], dp[i - 1][j])

# Minimum difference between the weights of the groups
min_diff = total_weight - 2 * dp[n][half_weight]
print(min_diff)
