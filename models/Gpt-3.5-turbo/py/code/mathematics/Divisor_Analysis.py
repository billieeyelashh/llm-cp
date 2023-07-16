
MOD = int(1e9+7)

# Step 1
n = int(input())
prime_factorization = [list(map(int, input().split())) for _ in range(n)]

# Step 2
num = 1
sum_divisors = 1
product_divisors = 1

# Step 3
for x, k in prime_factorization:
    num = (num * (k+1)) % MOD
    sum_divisors = (sum_divisors * (pow(x, k+1, MOD) - 1) * pow(x-1, MOD-2, MOD)) % MOD
    product_divisors = (product_divisors * pow(x, (k*(k+1)//2), MOD)) % MOD

# Step 4
print(num, sum_divisors, product_divisors)
