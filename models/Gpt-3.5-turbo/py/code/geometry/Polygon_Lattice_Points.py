
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lattice_points(n, vertices):
    area = 0
    boundary_points = 0

    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]

        area += x1 * y2 - x2 * y1
        boundary_points += gcd(abs(x1 - x2), abs(y1 - y2))

    area = abs(area) // 2
    interior_points = area - (boundary_points // 2) + 1

    return interior_points, boundary_points

# Read input
n = int(input())
vertices = []
for _ in range(n):
    x, y = map(int, input().split())
    vertices.append((x, y))

# Solve the problem
interior_points, boundary_points = lattice_points(n, vertices)

# Print the result
print(interior_points, boundary_points)
