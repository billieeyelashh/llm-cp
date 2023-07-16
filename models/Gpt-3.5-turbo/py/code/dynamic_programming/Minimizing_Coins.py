
n, x = map(int, input().split())
coins = list(map(int, input().split()))

dp = [float('inf')] * (x+1)
dp[0] = 0

for c in coins:
    for j in range(c, x+1):
        dp[j] = min(dp[j], dp[j-c]+1)

if dp[x] == float('inf'):
    print(-1)
else:
    print(dp[x])
