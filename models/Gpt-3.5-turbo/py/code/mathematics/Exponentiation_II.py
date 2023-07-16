
def modular_exponentiation(base, power, mod):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        power = power // 2
    return result

n = int(input())
for _ in range(n):
    a, b, c = map(int, input().split())
    power = modular_exponentiation(b, c, 10**9+6)
    result = modular_exponentiation(a, power, 10**9+7)
    print(result)
