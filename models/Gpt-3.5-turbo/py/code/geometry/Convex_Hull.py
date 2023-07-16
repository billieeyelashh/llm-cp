
def orientation(p, q, r):
    # Returns the orientation of the triplet (p, q, r)
    # 0 --> p, q, r are colinear
    # 1 --> Clockwise
    # 2 --> Counterclockwise
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2

def convex_hull(points):
    n = len(points)
    if n < 3:
        return []

    # Find the lowest point
    lowest = min(range(n), key=lambda i: (points[i][1], points[i][0]))

    # Sort points by polar angle
    points.sort(key=lambda p: (math.atan2(p[1] - points[lowest][1], p[0] - points[lowest][0]), p[0], p[1]))

    stack = [points[0], points[1]]

    for i in range(2, n):
        while len(stack) > 1 and orientation(stack[-2], stack[-1], points[i]) != 2:
            stack.pop()
        stack.append(points[i])

    return stack

# Read input
n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]

# Find the convex hull
hull = convex_hull(points)

# Print the number of points in the convex hull
print(len(hull))

# Print the points in the convex hull
for point in hull:
    print(point[0], point[1])
