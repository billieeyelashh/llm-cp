
n = int(input())
x = y = 0
visited = set()
distance = 0

for _ in range(n):
    d, dist = input().split()
    dist = int(dist)

    if d == 'U':
        y += dist
    elif d == 'D':
        y -= dist
    elif d == 'L':
        x -= dist
    elif d == 'R':
        x += dist

    distance += dist

    if (x, y) in visited:
        break

    visited.add((x, y))

print(distance)
