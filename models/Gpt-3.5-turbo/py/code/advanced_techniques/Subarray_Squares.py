
def minimum_cost(n, k, arr):
    dp = [[float('inf')] * (k+1) for _ in range(n+1)]
    dp[0][0] = 0
    
    prefix_sum = [0] * (n+1)
    for i in range(1, n+1):
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1]
    
    for i in range(1, n+1):
        for j in range(1, k+1):
            for t in range(i):
                dp[i][j] = min(dp[i][j], dp[t][j-1] + (prefix_sum[i] - prefix_sum[t])**2)
    
    return dp[n][k]

# Read input
n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Calculate and print the minimum total cost
print(minimum_cost(n, k, arr))
