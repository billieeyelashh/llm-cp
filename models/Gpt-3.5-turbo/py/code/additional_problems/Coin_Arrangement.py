
def min_moves(n, coins):
    total_moves = 0
    
    for i in range(2):
        for j in range(n):
            if coins[i][j] > 1:
                total_moves += abs(coins[i][j] - 1)
    
    return total_moves

# Read input
n = int(input())
coins = []
for _ in range(2):
    coins.append(list(map(int, input().split())))

# Call the function and print the result
print(min_moves(n, coins))
