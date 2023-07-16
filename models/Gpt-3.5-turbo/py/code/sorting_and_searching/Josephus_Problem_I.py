
from collections import deque

# Read the input
n = int(input())

# Create a deque with numbers from 1 to n
circle = deque(range(1, n+1))

# Initialize an empty list to store the removal order
removal_order = []

# Simulate the game until the circle is empty
while circle:
    # Remove the first child from the circle and append it to the removal order
    removal_order.append(circle.popleft())
    
    # If the circle is not empty, move the second child to the end
    if circle:
        circle.append(circle.popleft())

# Print the removal order
print(' '.join(map(str, removal_order)))
