
import math

def euclidean_distance(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

def minimum_distance(points):
    n = len(points)
    min_dist = float('inf')

    for i in range(n):
        for j in range(i+1, n):
            dist = euclidean_distance(points[i], points[j])
            min_dist = min(min_dist, dist)

    return min_dist

# Read input
n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

# Calculate minimum distance
min_dist = minimum_distance(points)

# Print result
print(min_dist)
