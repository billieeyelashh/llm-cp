
n, x = map(int, input().split())
weights = list(map(int, input().split()))

weights.sort()  # Sort the weights in non-decreasing order

# Initialize variables
gondola_count = 0
left = 0
right = n - 1

while left <= right:
    if weights[left] + weights[right] <= x:
        left += 1  # Pair up the child with the lowest weight and the child with the highest weight
    right -= 1  # Put the child with the highest weight in a separate gondola
    gondola_count += 1

print(gondola_count)
