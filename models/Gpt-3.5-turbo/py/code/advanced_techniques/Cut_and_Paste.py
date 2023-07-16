
from collections import deque

# Read input
n, m = map(int, input().split())
s = input()

# Initialize deque
dq = deque(s)

# Process operations
for _ in range(m):
    a, b = map(int, input().split())
    dq.rotate(n - b)  # Move substring from position a to position b to the end

# Convert deque to string
result = ''.join(dq)

# Print the final string
print(result)
