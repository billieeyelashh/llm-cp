
MOD = int(1e9+7)

def functional_graphs(n):
    dp = [[0] * (n+1) for _ in range(n+1)]
    
    # Base case: there is only one way to have a functional graph with 1 node and 1 component
    dp[1][1] = 1
    
    for i in range(2, n+1):
        for j in range(1, i+1):
            dp[i][j] = (dp[i-1][j-1] * (i-1) + dp[i-1][j] * j) % MOD
    
    for k in range(1, n+1):
        print(dp[n][k])
