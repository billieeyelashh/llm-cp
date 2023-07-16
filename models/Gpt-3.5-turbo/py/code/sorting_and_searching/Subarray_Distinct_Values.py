
n, k = map(int, input().split())
array = list(map(int, input().split()))

# Initialize variables
window = {}
count = 0
distinct_values = 0
left = 0

# Iterate over the array
for right in range(n):
    # Add the current element to the window
    window[array[right]] = window.get(array[right], 0) + 1
    
    # If the window has more than k distinct values, move the left pointer
    while distinct_values > k:
        window[array[left]] -= 1
        if window[array[left]] == 0:
            distinct_values -= 1
        left += 1
    
    # Update the count of subarrays
    count += right - left + 1
    
    # Update the number of distinct values in the window
    distinct_values = len(window)
    
print(count)
