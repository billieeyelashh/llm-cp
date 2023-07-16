
MOD = int(1e9) + 7

def calculate_bit_strings(n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        half = calculate_bit_strings(n // 2)
        return (half * half) % MOD
    else:
        half = calculate_bit_strings(n // 2)
        return (half * half * 2) % MOD

n = int(input())
result = calculate_bit_strings(n)
print(result)
