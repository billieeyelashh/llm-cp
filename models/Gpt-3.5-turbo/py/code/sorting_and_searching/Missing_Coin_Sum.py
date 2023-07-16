
n = int(input())
coins = list(map(int, input().split()))

coins.sort()  # Sort the coins in ascending order

smallest_sum = 1

for coin in coins:
    if coin <= smallest_sum:
        smallest_sum += coin
    else:
        break

print(smallest_sum)
