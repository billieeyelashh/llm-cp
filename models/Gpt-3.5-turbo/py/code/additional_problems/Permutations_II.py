
MOD = 10**9 + 7

def countBeautifulPermutations(n):
    dp = [[0] * (n+1) for _ in range(n+1)]

    for j in range(1, n+1):
        dp[1][j] = 1

    for i in range(2, n+1):
        for j in range(1, n+1):
            for k in range(1, n+1):
                if abs(j-k) > 1:
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD

    ans = sum(dp[n]) % MOD
    return ans

# Test the code
n = int(input())
print(countBeautifulPermutations(n))
