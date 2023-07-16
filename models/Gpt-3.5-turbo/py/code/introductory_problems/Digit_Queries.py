
def find_digit(q, positions):
    result = []
    for k in positions:
        length = 1
        count = 9
        while k > count * length:
            k -= count * length
            length += 1
            count *= 10

        num = 10 ** (length - 1) + (k - 1) // length
        digit = str(num)[(k - 1) % length]
        result.append(digit)

    return result


# Read the input
q = int(input())
positions = []
for _ in range(q):
    positions.append(int(input()))

# Call the function and print the output
output = find_digit(q, positions)
for digit in output:
    print(digit)
