
def solve(n):
    # Find the length of the longest subsequence
    length = len(bin(n)) - 2

    # Construct the bit string
    ans = '1' + '0' * (length - 1)

    return ans

# Read the input
n = int(input())

# Call the solve function and print the result
print(solve(n))
