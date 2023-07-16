
def count_divisions(n):
    S = n*(n+1)//2
    if S % 2 != 0:
        return 0
    
    target_sum = S // 2
    mod = int(1e9) + 7

    dp = [[0] * (target_sum + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        for j in range(target_sum + 1):
            dp[i][j] = dp[i - 1][j]
            if j >= i:
                dp[i][j] += dp[i - 1][j - i]
            dp[i][j] %= mod

    return dp[n][target_sum]

# Reading input
n = int(input())

# Calling the function and printing the result
print(count_divisions(n))
