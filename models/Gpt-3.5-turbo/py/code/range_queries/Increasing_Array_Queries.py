
n, q = map(int, input().split())
a = list(map(int, input().split()))

# dp[i] stores the minimum number of operations required to make a[i] greater than or equal to a[i-1]
dp = [0] * n

for i in range(1, n):
    if a[i] >= a[i-1]:
        dp[i] = dp[i-1]
    else:
        dp[i] = dp[i-1] + a[i-1] - a[i]

# Process the queries
for _ in range(q):
    a, b = map(int, input().split())
    # The minimum number of operations for the subarray from position a to position b is dp[b-1] - dp[a-1]
    print(dp[b-1] - dp[a-1])
