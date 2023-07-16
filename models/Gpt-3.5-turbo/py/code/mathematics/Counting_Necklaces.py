
from math import gcd

def count_distinct_necklaces(n, m):
    mod = int(1e9) + 7

    result = pow(m, n, mod)

    for d in range(1, n):
        if n % d == 0:
            result = (result + pow(m, gcd(n, d), mod)) % mod

    return (result * pow(n, -1, mod)) % mod

# Example usage:
n, m = map(int, input().split())
print(count_distinct_necklaces(n, m))
