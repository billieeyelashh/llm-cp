
MOD = 10**9 + 7

def count_ways(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]

    for i in range(n-1, -1, -1):
        dp[i][i] = 1
        for j in range(i+1, n):
            if s[i] == s[j]:
                dp[i][j] = (dp[i+1][j-1] + dp[i+1][j] + dp[i][j-1] + 2) % MOD
            else:
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]) % MOD

    return dp[0][n-1]

s = input()
print(count_ways(s))
