
MOD = 10**9 + 7

def modular_exponentiation(a, b):
    result = 1
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % MOD
        a = (a * a) % MOD
        b //= 2
    return result

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    print(modular_exponentiation(a, b))
