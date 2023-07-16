
MOD = int(1e9) + 7

def count_strings(n, m, pattern):
    dp = [[0] * m for _ in range(n+1)]

    # Base case: For strings of length 0, there is one string that matches the empty pattern
    dp[0][0] = 1

    for i in range(1, n+1):
        for j in range(m):
            for k in range(j+1):
                if pattern[k] == pattern[j]:
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD

    return sum(dp[n]) % MOD

# Read input
n = int(input())
pattern = input().strip()
m = len(pattern)

# Calculate and print the result
result = count_strings(n, m, pattern)
print(result)
