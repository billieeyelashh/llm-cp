
def count_pairs(binary_string):
    n = len(binary_string)
    one_bits = [0] * n
    count = 0
    
    # Calculate the number of one-bits at each position
    for i in range(n):
        if binary_string[i] == '1':
            count += 1
        one_bits[i] = count
    
    # Count the number of pairs for each distance k
    pairs = [0] * (n-1)
    for k in range(1, n):
        for i in range(n-k):
            if binary_string[i] == '1' and binary_string[i+k] == '1':
                pairs[k-1] += 1
    
    return pairs

# Read the binary string from input
binary_string = input().strip()

# Call the function and print the result
result = count_pairs(binary_string)
print(*result)
