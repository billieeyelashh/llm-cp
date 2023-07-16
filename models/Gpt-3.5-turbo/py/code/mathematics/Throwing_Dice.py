
MOD = 10**9 + 7

def count_ways(n):
    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        for j in range(1, 7):
            if i - j >= 0:
                dp[i] = (dp[i] + dp[i - j]) % MOD

    return dp[n]

# Read input
n = int(input())

# Compute and print the number of ways
print(count_ways(n))
