
MOD = 10**9 + 7

def count_ways(s):
    n = len(s)
    dp = [[0] * 26 for _ in range(n+1)]

    # Initialize dp[1][j] = 1 for each character j
    for j in range(26):
        dp[1][j] = 1

    for i in range(2, n+1):
        for j in range(26):
            for k in range(26):
                if j != k:
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD

    total_ways = 0
    for j in range(26):
        total_ways = (total_ways + dp[n][j]) % MOD

    return total_ways

# Test the solution with the provided example
s = 'aabc'
print(count_ways(s))
