
n = int(input())
row_counts = list(map(int, input().split()))
column_counts = list(map(int, input().split()))

grid = [['.'] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if row_counts[i] > 0 and column_counts[j] > 0:
            grid[i][j] = 'X'
            row_counts[i] -= 1
            column_counts[j] -= 1

# Check if all row and column counts are satisfied
for count in row_counts + column_counts:
    if count > 0:
        print(-1)
        exit()

# Print the grid
for row in grid:
    print(''.join(row))
