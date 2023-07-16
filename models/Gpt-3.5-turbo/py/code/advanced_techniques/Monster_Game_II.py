
def solve(n, x, s, f):
    dp = [0] * (n + 1)
    for i in range(n - 1, 0, -1):
        dp[i] = min(s[i] * f[i] + dp[i + 1], dp[i + 1])
    return dp[1]

# Read input
n, x = map(int, input().split())
s = [0] + list(map(int, input().split()))
f = [0] + list(map(int, input().split()))

# Solve problem and print result
result = solve(n, x, s, f)
print(result)
