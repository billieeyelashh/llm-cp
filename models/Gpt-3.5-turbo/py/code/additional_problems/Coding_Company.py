
MOD = int(1e9) + 7

def solve(n, x, skills):
    dp = [[0] * (x + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        min_skill = max_skill = skills[i - 1]
        for j in range(i, 0, -1):
            min_skill = min(min_skill, skills[j - 1])
            max_skill = max(max_skill, skills[j - 1])
            for k in range(max_skill - min_skill, x + 1):
                dp[i][k] = (dp[i][k] + dp[j - 1][k - (max_skill - min_skill)]) % MOD

        for j in range(x + 1):
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD

    return sum(dp[n]) % MOD

# Read input
n, x = map(int, input().split())
skills = list(map(int, input().split()))

# Solve the problem
result = solve(n, x, skills)

# Print the result
print(result)
