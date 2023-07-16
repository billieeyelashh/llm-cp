
n, k = map(int, input().split())
children = list(map(int, input().split()))

# Initialize dp array with a large value
dp = [[float('inf')] * (k+1) for _ in range(n+1)]
dp[0][0] = 0

for i in range(1, n+1):
    # Calculate prefix sum of children in houses
    prefix_sum = [0] * (n+1)
    for j in range(1, n+1):
        prefix_sum[j] = prefix_sum[j-1] + children[j-1]

    for j in range(1, k+1):
        for p in range(i, 0, -1):
            # Calculate the minimum distance for each position to establish the last school
            dp[i][j] = min(dp[i][j], dp[p-1][j-1] + (prefix_sum[i] - prefix_sum[p-1]) - children[p-1])

print(dp[n][k])
