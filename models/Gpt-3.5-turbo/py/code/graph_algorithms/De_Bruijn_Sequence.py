
n = int(input())

# Construct the bit string
bit_string = '0' * (n-1) + '1' + '0' * (n-1)[::-1]

# Print the bit string
print(bit_string)
