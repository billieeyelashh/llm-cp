
def assign_hotels(n, m, hotels, groups):
    # Initialize a list to store the assigned hotel for each group
    assigned_hotels = [0] * m

    # Iterate through each group
    for i in range(m):
        # Iterate through each hotel
        for j in range(n):
            # If the hotel has enough free rooms, assign the group to it
            if hotels[j] >= groups[i]:
                assigned_hotels[i] = j + 1
                hotels[j] -= groups[i]
                break

    # Return the assigned hotels
    return assigned_hotels

# Read the input values
n, m = map(int, input().split())
hotels = list(map(int, input().split()))
groups = list(map(int, input().split()))

# Call the function and print the result
result = assign_hotels(n, m, hotels, groups)
print(*result)
