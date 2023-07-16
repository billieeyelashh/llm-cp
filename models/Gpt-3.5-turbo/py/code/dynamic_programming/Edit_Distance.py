
def edit_distance(s1, s2):
    n = len(s1)
    m = len(s2)
    
    # Initialize the dp matrix
    dp = [[0] * (m+1) for _ in range(n+1)]
    
    # Fill in the base cases
    for i in range(n+1):
        dp[i][0] = i
    for j in range(m+1):
        dp[0][j] = j
    
    # Compute the edit distance
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1)
    
    return dp[n][m]

# Read the input strings
s1 = input().strip()
s2 = input().strip()

# Compute and print the edit distance
print(edit_distance(s1, s2))
