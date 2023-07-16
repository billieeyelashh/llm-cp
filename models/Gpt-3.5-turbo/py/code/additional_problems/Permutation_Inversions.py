
MOD = int(1e9) + 7

def count_permutations(n, k):
    dp = [[0] * (k+1) for _ in range(n+1)]
    dp[1][0] = 1

    for i in range(2, n+1):
        dp[i][0] = 1
        for j in range(1, k+1):
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD
            if j >= i:
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD

    return dp[n][k]

n, k = map(int, input().split())
print(count_permutations(n, k))
