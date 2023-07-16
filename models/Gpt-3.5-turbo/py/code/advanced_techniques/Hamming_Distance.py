
n, k = map(int, input().split())
strings = [input() for _ in range(n)]

min_distance = float('inf')

for i in range(n):
    for j in range(i+1, n):
        distance = bin(int(strings[i], 2) ^ int(strings[j], 2)).count('1')
        min_distance = min(min_distance, distance)

print(min_distance)
