
def find_money_sums(n, coins):
    sums = {0}  # Set to store the possible sums
    for coin in coins:
        new_sums = set()
        for s in sums:
            new_sums.add(s + coin)
        sums.update(new_sums)
    return len(sums), sorted(sums)

# Example usage
n = 4
coins = [4, 2, 5, 2]
num_sums, sums = find_money_sums(n, coins)
print(num_sums)
print(*sums)
