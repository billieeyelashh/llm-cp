
from collections import defaultdict

def count_ways(k, n, m, apples, bananas):
    # Initialize hash tables to store the frequency of each weight
    apple_weights = defaultdict(int)
    banana_weights = defaultdict(int)

    # Count the frequency of each weight for apples and bananas
    for apple in apples:
        apple_weights[apple] += 1
    for banana in bananas:
        banana_weights[banana] += 1

    # Calculate the number of ways for each weight from 2 to 2k
    ways = [0] * (2 * k + 1)
    for w in range(2, 2 * k + 1):
        for apple_weight in range(1, min(w, k + 1)):
            banana_weight = w - apple_weight
            ways[w] += apple_weights[apple_weight] * banana_weights[banana_weight]

    return ways[2:]

# Read input
k, n, m = map(int, input().split())
apples = list(map(int, input().split()))
bananas = list(map(int, input().split()))

# Calculate and print the number of ways for each weight
ways = count_ways(k, n, m, apples, bananas)
print(*ways)
