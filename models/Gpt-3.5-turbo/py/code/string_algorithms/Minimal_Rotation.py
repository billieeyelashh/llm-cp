
def lexicographically_minimal_rotation(s):
    n = len(s)
    s += s  # concatenate the string to itself

    # initialize the lexicographically minimal rotation
    min_rotation = s[:n]

    # iterate through all possible rotations
    for i in range(1, n):
        rotation = s[i:i+n]
        if rotation < min_rotation:
            min_rotation = rotation

    return min_rotation

# Input
s = input()

# Output
print(lexicographically_minimal_rotation(s))
