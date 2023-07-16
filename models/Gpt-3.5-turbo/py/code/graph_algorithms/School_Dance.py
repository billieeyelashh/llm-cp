
# Read input
n, m, k = map(int, input().split())

# Initialize arrays to keep track of availability
boys = [True] * n
girls = [True] * m

# Initialize an array to store the dance pairs
pairs = []

# Iterate through all potential pairs
for _ in range(k):
    a, b = map(int, input().split())
    
    # Check if the boy and girl are available
    if boys[a-1] and girls[b-1]:
        # Mark the boy and girl as unavailable
        boys[a-1] = False
        girls[b-1] = False
        
        # Add the pair to the list of pairs
        pairs.append((a, b))

# Print the maximum number of dance pairs
print(len(pairs))

# Print the pairs
for pair in pairs:
    print(pair[0], pair[1])
