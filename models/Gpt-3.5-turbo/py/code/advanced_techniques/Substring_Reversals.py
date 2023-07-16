
# Read input
n, m = map(int, input().split())
s = input()

# Apply each operation
for _ in range(m):
    a, b = map(int, input().split())
    # Reverse the substring from position a to position b
    s = s[:a-1] + s[a-1:b][::-1] + s[b:]

# Print the final string
print(s)
