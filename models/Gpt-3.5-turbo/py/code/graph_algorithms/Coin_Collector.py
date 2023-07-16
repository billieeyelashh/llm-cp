
n, m = map(int, input().split())
coins = list(map(int, input().split()))

dp = coins.copy()

for _ in range(m):
    a, b = map(int, input().split())
    dp[b-1] = max(dp[b-1], dp[a-1] + coins[b-1])

max_coins = max(dp)
print(max_coins)
