
n = int(input())

steps = 0
while n > 0:
    smallest_digit = min([int(digit) for digit in str(n)])
    n -= smallest_digit
    steps += 1

print(steps)
