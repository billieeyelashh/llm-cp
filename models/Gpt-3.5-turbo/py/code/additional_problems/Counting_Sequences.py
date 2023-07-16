
MOD = int(1e9) + 7

def count_sequences(n, k):
    result = pow(k, n, MOD)  # Calculate k^n % MOD
    for i in range(1, k):
        coeff = pow(-1, i) * comb(k, i)  # Calculate (-1)^i * binomial coefficient
        result += coeff * pow(k - i, n, MOD)  # Add/subtract the term to the result
        result %= MOD  # Take modulo after each step to avoid overflow
    return result

def comb(n, r):
    # Calculate binomial coefficient (n choose r) % MOD using dynamic programming
    C = [[0] * (r + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for j in range(min(i, r) + 1):
            if j == 0 or j == i:
                C[i][j] = 1
            else:
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD
    return C[n][r]

# Read input
n, k = map(int, input().split())

# Count sequences and print the result
print(count_sequences(n, k))
