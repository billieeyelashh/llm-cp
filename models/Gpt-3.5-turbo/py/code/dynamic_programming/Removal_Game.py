
n = int(input())
x = list(map(int, input().split()))

# Initialize DP table with zeros
DP = [[0] * n for _ in range(n)]

# Base case
for i in range(n):
    DP[i][i] = x[i]

# Fill the DP table
for gap in range(1, n):
    for i in range(n - gap):
        j = i + gap
        DP[i][j] = max(
            x[i] + min(DP[i + 2][j], DP[i + 1][j - 1]),
            x[j] + min(DP[i + 1][j - 1], DP[i][j - 2])
        )

# The maximum possible score for the first player is DP[0][n-1]
print(DP[0][n - 1])
