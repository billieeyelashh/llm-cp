
MOD = 10**9 + 7

def count_valid_sequences(n):
    dp = [0] * (n+1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2, n+1):
        for j in range(i):
            dp[i] += dp[j] * dp[i-j-1]
            dp[i] %= MOD

    return dp[n]

# Read input
n = int(input())

# Calculate and print the result
result = count_valid_sequences(n)
print(result)
