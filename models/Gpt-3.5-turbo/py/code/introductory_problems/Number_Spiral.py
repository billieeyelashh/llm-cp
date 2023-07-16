
# Function to find the number in row y and column x
def number_in_spiral(y, x):
    diff = abs(y - x)
    max_value = max(y, x)
    return max_value ** 2 - (max_value - 1) + diff

# Read the number of tests
t = int(input())

# Iterate through each test case
for _ in range(t):
    # Read the values of y and x
    y, x = map(int, input().split())
    
    # Print the number in row y and column x
    print(number_in_spiral(y, x))
