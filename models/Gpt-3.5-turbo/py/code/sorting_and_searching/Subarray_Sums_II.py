
def count_subarrays_with_sum(arr, n, x):
    count = 0
    prefix_sum = {0: 1}
    current_sum = 0
    
    for num in arr:
        current_sum += num
        if current_sum - x in prefix_sum:
            count += prefix_sum[current_sum - x]
        prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1
    
    return count

# Read input
n, x = map(int, input().split())
arr = list(map(int, input().split()))

# Call the function to count subarrays with sum x
result = count_subarrays_with_sum(arr, n, x)

# Print the result
print(result)
