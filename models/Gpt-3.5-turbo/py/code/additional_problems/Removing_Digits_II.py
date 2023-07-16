
def min_steps(n):
    # Base case: if n is 0, no steps are required
    if n == 0:
        return 0
    
    # Initialize minimum steps to a large value
    min_steps = float('inf')
    
    # Iterate through each digit of n
    for digit in str(n):
        # Subtract the digit from n and call min_steps recursively
        steps = 1 + min_steps(n - int(digit))
        
        # Update the minimum steps
        min_steps = min(min_steps, steps)
    
    return min_steps

# Read the input
n = int(input())

# Call the min_steps function and print the result
print(min_steps(n))
