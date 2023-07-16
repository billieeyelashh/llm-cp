
def process_signal(signal, mask):
    n = len(signal)
    m = len(mask)
    
    result = []
    
    # Iterate through each mask position
    for i in range(n + m - 1):
        # Calculate the starting and ending indices for signal
        start = max(0, i - m + 1)
        end = min(i + 1, n)
        
        # Calculate the sum of products for the current mask position
        sum_of_products = sum(signal[j] * mask[i - j] for j in range(start, end))
        
        result.append(sum_of_products)
    
    return result

# Read input
n, m = map(int, input().split())
signal = list(map(int, input().split()))
mask = list(map(int, input().split()))

# Call the function to process the signal
output = process_signal(signal, mask)

# Print the output
print(*output)
