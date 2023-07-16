
n, x = map(int, input().split())
s = list(map(int, input().split()))
f = list(map(int, input().split()))

dp = [0] * (n+1)
for i in range(n-1, 0, -1):
    dp[i] = float('inf')
    for j in range(i+1, n+1):
        if s[j-1] >= s[i-1]:
            dp[i] = min(dp[i], s[i-1]*f[i-1] + dp[j])

print(dp[1])
