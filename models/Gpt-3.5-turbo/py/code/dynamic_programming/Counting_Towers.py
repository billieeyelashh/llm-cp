
MOD = int(1e9) + 7

def countTowers(n):
    dp = [0] * (n + 1)
    dp[0] = dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = (dp[i-1] + dp[i-2]) % MOD

    return dp[n]

# Read the number of tests
t = int(input())

# Iterate over each test case
for _ in range(t):
    n = int(input())
    result = countTowers(n)
    print(result)
