
n, x = map(int, input().split())
weights = list(map(int, input().split()))

weights.sort()  # Sort the weights in non-decreasing order

rides = 0
left = 0  # Index of the heaviest person on the left side of the elevator
right = n - 1  # Index of the lightest person on the right side of the elevator

while left <= right:
    if weights[left] + weights[right] <= x:
        # If the weights of the heaviest and lightest person can fit in one ride
        left += 1  # Move the index of the heaviest person towards the right
    right -= 1  # Move the index of the lightest person towards the left
    rides += 1  # Increment the number of rides

print(rides)
