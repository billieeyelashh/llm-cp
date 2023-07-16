
n = int(input())
for _ in range(n):
    x = int(input())
    divisors = 0
    for i in range(1, x+1):
        if x % i == 0:
            divisors += 1
    print(divisors)
