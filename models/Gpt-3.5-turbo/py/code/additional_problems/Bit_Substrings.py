
def count_substrings(s):
    n = len(s)
    prefix_sum = [0] * (n + 1)

    # Calculate prefix sum of ones
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + int(s[i - 1])

    # Count substrings for each k
    result = [0] * (n + 1)
    for i in range(n + 1):
        for j in range(i + 1, n + 1):
            ones = prefix_sum[j] - prefix_sum[i]
            result[ones] += 1

    return result

# Read input
s = input().strip()

# Calculate and print the result
result = count_substrings(s)
print(' '.join(map(str, result)))
