
n = int(input())
projects = []

for _ in range(n):
    a, b, p = map(int, input().split())
    projects.append((b, a, p))

projects.sort()  # sort based on ending days

dp = [0] * (n + 1)

for i in range(1, n + 1):
    # maximum amount of money without attending the current project
    dp[i] = dp[i - 1]
    
    # find the last project that ends before the start of the current project
    j = i - 1
    while j >= 0 and projects[j][0] >= projects[i - 1][1]:
        j -= 1
    
    # consider attending the current project and update the maximum amount of money
    dp[i] = max(dp[i], dp[j + 1] + projects[i - 1][2])

print(dp[n])
