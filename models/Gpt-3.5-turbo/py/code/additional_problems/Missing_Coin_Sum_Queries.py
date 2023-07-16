
# Read input
n, q = map(int, input().split())
coins = list(map(int, input().split()))

# Sort the coins in ascending order
coins.sort()

# Process each query
for _ in range(q):
    a, b = map(int, input().split())
    
    # Initialize the smallest sum
    smallest_sum = 1
    
    # Iterate through the coins from a to b
    for i in range(a-1, b):
        if coins[i] > smallest_sum:
            # Found the answer for the current query
            print(smallest_sum)
            break
        else:
            # Update smallest_sum
            smallest_sum += coins[i]
    else:
        # If the loop completes without finding an answer, the smallest sum is the sum of all coins
        print(smallest_sum)
