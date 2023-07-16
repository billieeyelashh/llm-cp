
n = int(input())
row_counts = list(map(int, input().split()))
col_counts = list(map(int, input().split()))

grid = []
for _ in range(n):
    row = list(map(int, input().split()))
    grid.append(row)

chosen = [['.'] * n for _ in range(n)]
coins = 0

for i in range(n):
    for _ in range(row_counts[i]):
        max_coins = -1
        max_col = -1
        for j in range(n):
            if grid[i][j] > max_coins and col_counts[j] > 0:
                max_coins = grid[i][j]
                max_col = j
        
        if max_coins == -1:
            print(-1)
            exit()
        
        chosen[i][max_col] = 'X'
        coins += max_coins
        col_counts[max_col] -= 1

print(coins)
for row in chosen:
    print(''.join(row))
