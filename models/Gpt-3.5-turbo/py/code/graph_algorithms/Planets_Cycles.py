
n = int(input())
teleporters = list(map(int, input().split()))

teleportations = [0] * n

for start_planet in range(1, n+1):
    visited = set()
    current_planet = start_planet
    while current_planet not in visited:
        visited.add(current_planet)
        current_planet = teleporters[current_planet-1]
        teleportations[start_planet-1] += 1

print(" ".join(map(str, teleportations)))
