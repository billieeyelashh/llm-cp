
# Read the input DNA sequence
sequence = input()

# Initialize variables
max_repetition = 0
current_repetition = 0
prev_char = None

# Iterate through the sequence
for char in sequence:
    # If the current character is the same as the previous one
    if char == prev_char:
        current_repetition += 1
    # If the current character is different
    else:
        # Update the maximum repetition length if necessary
        max_repetition = max(max_repetition, current_repetition)
        # Reset the current repetition length
        current_repetition = 1
        # Update the previous character
        prev_char = char

# Update the maximum repetition length after the last character
max_repetition = max(max_repetition, current_repetition)

# Print the result
print(max_repetition)
