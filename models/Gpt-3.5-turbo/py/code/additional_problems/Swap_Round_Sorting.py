
def solve(n, arr):
    rounds = []
    positions = [0] * (n + 1)
    
    for i in range(n):
        positions[arr[i]] = i + 1
    
    for i in range(1, n + 1):
        while arr[i - 1] != i:
            j = positions[i]
            rounds.append([(i, j)])
            arr[i - 1], arr[j - 1] = arr[j - 1], arr[i - 1]
            positions[arr[i - 1]], positions[arr[j - 1]] = positions[arr[j - 1]], positions[arr[i - 1]]
    
    return rounds

# Read input
n = int(input())
arr = list(map(int, input().split()))

# Solve the problem
rounds = solve(n, arr)

# Print the output
print(len(rounds))
for round in rounds:
    print(len(round))
    for swap in round:
        print(*swap)
