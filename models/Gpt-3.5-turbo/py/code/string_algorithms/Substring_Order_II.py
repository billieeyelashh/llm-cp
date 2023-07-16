
# Step 1: Read input
s = input().strip()
k = int(input())

# Step 2: Create list of tuples (suffix, starting index)
suffixes = [(s[i:], i) for i in range(len(s))]

# Step 3: Sort the list of tuples
suffixes.sort()

# Step 4: Concatenate all suffixes to form suffix array
suffix_array = ''.join([suffix[0] for suffix in suffixes])

# Step 5: Find kth smallest substring
kth_smallest_substring = suffix_array[k-1:]

# Step 6: Print result
print(kth_smallest_substring)
