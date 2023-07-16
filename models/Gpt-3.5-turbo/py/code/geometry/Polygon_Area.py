
def calculate_area(n, vertices):
    area = 0
    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]
        area += x1 * y2 - x2 * y1
    return abs(area) // 2

n = int(input())
vertices = []
for _ in range(n):
    x, y = map(int, input().split())
    vertices.append((x, y))

area = calculate_area(n, vertices)
print(2 * area)
