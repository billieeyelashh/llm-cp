
def kth_smallest_substring(s, k):
    n = len(s)
    substrings = set()
    
    # Generate all distinct substrings
    for length in range(1, n+1):
        for start in range(n-length+1):
            substrings.add(s[start:start+length])
    
    # Sort the distinct substrings lexicographically
    sorted_substrings = sorted(substrings)
    
    # Return the kth smallest distinct substring
    return sorted_substrings[k-1]

# Read the input
s = input().strip()
k = int(input())

# Call the function and print the result
print(kth_smallest_substring(s, k))
