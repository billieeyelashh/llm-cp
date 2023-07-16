
from collections import Counter

def reorder_to_palindrome(s):
    char_freq = Counter(s)
    odd_freq_count = 0
    odd_char = ''
    
    # Count the number of characters with odd frequency
    for char, freq in char_freq.items():
        if freq % 2 != 0:
            odd_freq_count += 1
            odd_char = char
    
    # If there is more than one character with odd frequency, return "NO SOLUTION"
    if odd_freq_count > 1:
        return "NO SOLUTION"
    
    palindrome = []
    
    # Add half of the frequency of each character to the left and right side of the middle character
    for char, freq in char_freq.items():
        half_freq = freq // 2
        if half_freq > 0:
            palindrome.extend([char] * half_freq)
    
    # If there is a character with odd frequency, add it to the middle
    if odd_char != '':
        palindrome.append(odd_char)
    
    # Add the reversed half of the palindrome to the right side
    palindrome.extend(palindrome[::-1])
    
    return ''.join(palindrome)

# Test the function
s = "AAAACACBA"
print(reorder_to_palindrome(s))
