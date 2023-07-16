
# Read input
n, m, k = map(int, input().split())
desired_sizes = list(map(int, input().split()))
apartment_sizes = list(map(int, input().split()))

# Sort both lists
desired_sizes.sort()
apartment_sizes.sort()

# Initialize variables
i = 0  # Pointer for desired_sizes
j = 0  # Pointer for apartment_sizes
count = 0  # Counter for the number of applicants who will get an apartment

# Iterate through both lists
while i < n and j < m:
    # Check if the current apartment size is within the desired range
    if abs(desired_sizes[i] - apartment_sizes[j]) <= k:
        count += 1
        i += 1
        j += 1
    # If the current apartment size is too small, move to the next apartment size
    elif desired_sizes[i] - apartment_sizes[j] > k:
        j += 1
    # If the current apartment size is too large, move to the next desired size
    else:
        i += 1

# Print the result
print(count)
