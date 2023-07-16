
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

n, k = map(int, input().split())
primes = list(map(int, input().split()))

divisible_by_prime = [n // prime for prime in primes]

divisible_by_two_primes = 0
for i in range(k):
    for j in range(i + 1, k):
        divisible_by_two_primes += n // lcm(primes[i], primes[j])

answer = sum(divisible_by_prime) - divisible_by_two_primes

print(answer)
