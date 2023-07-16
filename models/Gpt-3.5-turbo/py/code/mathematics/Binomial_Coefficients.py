
MOD = 10**9 + 7

def binomial_coefficient(a, b):
    # Calculate a!
    numerator = 1
    for i in range(1, a+1):
        numerator = (numerator * i) % MOD

    # Calculate b! and (a-b)!
    denominator = 1
    for i in range(1, b+1):
        denominator = (denominator * i) % MOD
    for i in range(1, a-b+1):
        denominator = (denominator * i) % MOD

    # Calculate (a! / (b! * (a-b)!)) % MOD
    inv_denominator = pow(denominator, MOD-2, MOD)  # Calculate the modular multiplicative inverse of denominator
    binomial_coeff = (numerator * inv_denominator) % MOD

    return binomial_coeff

# Read input
n = int(input())
coefficients = []
for _ in range(n):
    a, b = map(int, input().split())
    coefficients.append((a, b))

# Calculate and print binomial coefficients
for a, b in coefficients:
    print(binomial_coefficient(a, b))
