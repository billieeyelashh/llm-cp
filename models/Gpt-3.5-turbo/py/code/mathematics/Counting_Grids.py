
MOD = 10**9 + 7

def count_grids(n):
    return pow(2, n * n, MOD)

# Read input
n = int(input())

# Calculate and print the answer
print(count_grids(n))
