
from collections import defaultdict

def calculate_costs(n, k, arr):
    costs = []

    # Initialize the frequency of each element in the window
    freq = defaultdict(int)
    
    # Calculate the median value of the current window
    def calculate_median():
        sorted_keys = sorted(freq.keys())
        count = 0
        
        # Find the median element(s)
        for key in sorted_keys:
            count += freq[key]
            if count >= (k + 1) // 2:
                median = key
                break
        
        return median
    
    # Calculate the initial median of the first window
    for i in range(k):
        freq[arr[i]] += 1
    median = calculate_median()
    
    # Calculate the costs for the remaining windows
    for i in range(n - k + 1):
        # Add the cost for the current window to the result
        costs.append(sum(abs(arr[j] - median) for j in range(i, i + k)))
        
        # Update the frequency of the elements in the current window
        freq[arr[i]] -= 1
        freq[arr[i + k]] += 1
        
        # Update the median if necessary
        if arr[i] <= median <= arr[i + k]:
            median = calculate_median()
        
    return costs

# Read the input
n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Calculate and print the costs
costs = calculate_costs(n, k, arr)
print(*costs)
