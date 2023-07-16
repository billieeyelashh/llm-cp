
def count_special_substrings(s):
    n = len(s)
    count = 0

    # Iterate through each character as the center of the window
    for i in range(n):
        # Initialize a dictionary to keep track of character frequencies
        freq = {}

        # Expand the window to the right
        j = i
        while j < n:
            # Increment the frequency of the current character
            freq[s[j]] = freq.get(s[j], 0) + 1

            # Check if all characters in the window have the same frequency
            if len(freq.values()) == len(set(freq.values())):
                count += 1

            # Move to the next character
            j += 1

    return count

# Test the function with the given example
s = "abccabab"
print(count_special_substrings(s))
