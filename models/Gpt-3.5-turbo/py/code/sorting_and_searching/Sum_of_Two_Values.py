
n, x = map(int, input().split())
arr = list(map(int, input().split()))

# Create a hashmap to store the values
hashmap = {}

# Iterate through the array
for i in range(n):
    # Check if the complement exists in the hashmap
    complement = x - arr[i]
    if complement in hashmap:
        # If it does, print the positions and exit
        print(hashmap[complement], i+1)
        exit()
    
    # Add the current element to the hashmap
    hashmap[arr[i]] = i+1

# If no solution is found, print IMPOSSIBLE
print("IMPOSSIBLE")
