
n, q = map(int, input().split())
t = list(map(int, input().split()))

# Precompute the dp array
log_k = int(math.log2(max(q for _, q in queries)) + 1)
dp = [[0] * log_k for _ in range(n)]
for i in range(n):
    dp[i][0] = t[i]

for j in range(1, log_k):
    for i in range(n):
        dp[i][j] = dp[dp[i][j-1]][j-1]

# Answer each query
for _ in range(q):
    x, k = map(int, input().split())

    # Find the planet after travelling through k teleporters
    current = x
    for i in range(log_k-1, -1, -1):
        if k & (1 << i):
            current = dp[current][i]

    print(current)
