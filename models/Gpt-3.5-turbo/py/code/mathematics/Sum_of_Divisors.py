
MOD = 10**9 + 7

def prime_factorization(n):
    factors = {}
    i = 2
    while i * i <= n:
        while n % i == 0:
            n //= i
            factors[i] = factors.get(i, 0) + 1
        i += 1
    if n > 1:
        factors[n] = factors.get(n, 0) + 1
    return factors

def solve(n):
    ans = 0
    for i in range(1, n+1):
        factors = prime_factorization(i)
        sigma_i = 1
        for factor, power in factors.items():
            term = (pow(factor, power+1, MOD) - 1) * pow(factor-1, MOD-2, MOD)
            sigma_i = (sigma_i * term) % MOD
        ans = (ans + sigma_i) % MOD
    return ans

n = int(input())
print(solve(n))
