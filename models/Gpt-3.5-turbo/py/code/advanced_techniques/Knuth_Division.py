
# Read input
n = int(input())
array = list(map(int, input().split()))

# Sort the array in non-decreasing order
array.sort()

# Initialize total cost
total_cost = 0

# Iterate over the sorted array
for i in range(n):
    # Calculate the cost of splitting the current subarray
    cost = array[i] * (n-i)
    # Add the cost to the total cost
    total_cost += cost

# Print the minimum total cost
print(total_cost)
