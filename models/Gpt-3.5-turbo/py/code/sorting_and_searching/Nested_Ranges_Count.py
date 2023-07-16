
n = int(input())
ranges = []
for _ in range(n):
    x, y = map(int, input().split())
    ranges.append((x, y))

# Sort the ranges based on the starting point
ranges.sort()

# Initialize counts for each range
contains_count = [0] * n
contained_by_count = [0] * n

# Count how many other ranges each range contains
max_end = float('-inf')
for i in range(n):
    if ranges[i][1] <= max_end:
        contains_count[i] = 1
    else:
        max_end = ranges[i][1]

# Count how many other ranges contain each range
min_start = float('inf')
for i in range(n-1, -1, -1):
    if ranges[i][0] >= min_start:
        contained_by_count[i] = 1
    else:
        min_start = ranges[i][0]

# Print the counts for each range
print(' '.join(map(str, contains_count)))
print(' '.join(map(str, contained_by_count)))
