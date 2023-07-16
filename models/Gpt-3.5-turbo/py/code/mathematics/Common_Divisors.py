
from math import gcd

def find_max_gcd(n, arr):
    max_gcd = 0
    
    for i in range(n):
        for j in range(i+1, n):
            max_gcd = max(max_gcd, gcd(arr[i], arr[j]))
    
    return max_gcd

# Read input
n = int(input())
arr = list(map(int, input().split()))

# Find maximum GCD
max_gcd = find_max_gcd(n, arr)

# Print output
print(max_gcd)
