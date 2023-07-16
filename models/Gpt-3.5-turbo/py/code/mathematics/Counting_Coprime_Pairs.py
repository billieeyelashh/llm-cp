
def gcd(a, b):
    # Euclidean algorithm to find the greatest common divisor
    while b != 0:
        a, b = b, a % b
    return a

def count_coprime_pairs(n, arr):
    count = 0
    
    for i in range(n):
        for j in range(i+1, n):
            if gcd(arr[i], arr[j]) == 1:
                count += 1
    
    return count

# Read input
n = int(input())
arr = list(map(int, input().split()))

# Compute and print the result
result = count_coprime_pairs(n, arr)
print(result)
