
n, x = map(int, input().split())
array = list(map(int, input().split()))

# Iterate over all possible combinations of three values
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            # Check if the sum is equal to the target sum
            if array[i] + array[j] + array[k] == x:
                print(i+1, j+1, k+1)
                exit()

# If no valid combination is found, print IMPOSSIBLE
print("IMPOSSIBLE")
