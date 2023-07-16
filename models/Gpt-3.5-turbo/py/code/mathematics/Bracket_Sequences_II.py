
MOD = int(1e9) + 7

def count_sequences(n, prefix):
    dp = [[0] * (n+1) for _ in range(len(prefix)+1)]
    dp[0][0] = 1

    for i in range(1, len(prefix)+1):
        for j in range(n+1):
            if prefix[i-1] == '(':
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD
            else:
                dp[i][j] = dp[i-1][j+1]

    return dp[len(prefix)][0]

n = int(input())
prefix = input()

result = count_sequences(n, prefix)
print(result)
