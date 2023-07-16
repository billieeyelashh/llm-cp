
MOD = int(1e9) + 7

def count_ways(grid, n, row, col, used_rows, used_cols):
    # Base case: if all cells are filled, return 1
    if row == n:
        return 1

    # If the current cell is already filled, move to the next cell
    if grid[row][col] != '.':
        next_row = row + (col + 1) // n
        next_col = (col + 1) % n
        return count_ways(grid, n, next_row, next_col, used_rows, used_cols)

    count = 0
    # Try placing A in the current cell
    if not used_rows[row] and not used_cols[col]:
        used_rows[row] = True
        used_cols[col] = True
        next_row = row + (col + 1) // n
        next_col = (col + 1) % n
        count += count_ways(grid, n, next_row, next_col, used_rows, used_cols)
        used_rows[row] = False
        used_cols[col] = False

    # Try placing B in the current cell
    if not used_rows[row] and not used_cols[col]:
        used_rows[row] = True
        used_cols[col] = True
        next_row = row + (col + 1) // n
        next_col = (col + 1) % n
        count += count_ways(grid, n, next_row, next_col, used_rows, used_cols)
        used_rows[row] = False
        used_cols[col] = False

    return count % MOD

n = int(input())
grid = []
for _ in range(n):
    grid.append(input())

used_rows = [False] * n
used_cols = [False] * n

print(count_ways(grid, n, 0, 0, used_rows, used_cols))
