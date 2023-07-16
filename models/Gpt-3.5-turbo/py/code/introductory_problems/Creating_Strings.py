
def generate_permutations(s):
    # Set to store unique permutations
    permutations = set()

    def backtrack(s, curr):
        # Base case: if the current permutation is of length n
        if len(curr) == len(s):
            permutations.add(curr)
            return
        
        # Recursive case: try all possible characters at the current position
        for i in range(len(s)):
            if s[i] not in curr:
                # Add the character to the current permutation
                curr += s[i]
                # Recursively generate permutations
                backtrack(s, curr)
                # Remove the character for backtracking
                curr = curr[:-1]

    # Start backtracking
    backtrack(s, "")

    return permutations

# Driver code
s = input().strip()
permutations = generate_permutations(s)

# Print the number of strings and the strings in alphabetical order
print(len(permutations))
for p in sorted(permutations):
    print(p)
