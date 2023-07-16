
# Read input
n = int(input())
grid = [input() for _ in range(n)]

# Count the number of coins in each row and column
row_coins = [row.count('o') for row in grid]
col_coins = [sum(grid[i][j] == 'o' for i in range(n)) for j in range(n)]

# Greedy removal of rows and columns with maximum coins
moves = []
while sum(row_coins) > 0 or sum(col_coins) > 0:
    max_row_coins = max(row_coins)
    max_col_coins = max(col_coins)

    if max_row_coins >= max_col_coins:
        row = row_coins.index(max_row_coins) + 1
        moves.append((1, row))
        row_coins[row - 1] = 0
        for j in range(n):
            if grid[row - 1][j] == 'o':
                col_coins[j] -= 1
    else:
        col = col_coins.index(max_col_coins) + 1
        moves.append((2, col))
        col_coins[col - 1] = 0
        for i in range(n):
            if grid[i][col - 1] == 'o':
                row_coins[i] -= 1

# Print the solution
print(len(moves))
for move in moves:
    print(*move)
