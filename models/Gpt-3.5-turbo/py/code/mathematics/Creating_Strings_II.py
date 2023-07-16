
from math import factorial

# Read the input string
s = input()

# Count the frequency of each character
freq = {}
for ch in s:
    freq[ch] = freq.get(ch, 0) + 1

# Calculate the factorial of the length of the string
result = factorial(len(s))

# Divide the factorial by the product of factorials of the character counts
for count in freq.values():
    result //= factorial(count)

# Print the result modulo 10^9+7
print(result % (10**9 + 7))
