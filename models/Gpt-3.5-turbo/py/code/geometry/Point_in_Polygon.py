
def orientation(x1, y1, x2, y2, x3, y3):
    # Calculate the orientation of three points (x1, y1), (x2, y2), (x3, y3)
    # Returns 0 if the points are collinear, 1 if clockwise, and 2 if counterclockwise
    val = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1)
    if val == 0:
        return 0  # Collinear
    elif val > 0:
        return 1  # Clockwise
    else:
        return 2  # Counterclockwise

def on_boundary(x1, y1, x2, y2, x, y):
    # Check if the point (x, y) lies on the boundary of the line segment (x1, y1) to (x2, y2)
    if x >= min(x1, x2) and x <= max(x1, x2) and y >= min(y1, y2) and y <= max(y1, y2):
        if (y2 - y1) * (x - x1) == (y - y1) * (x2 - x1):
            return True
    return False

def inside_polygon(polygon, x, y):
    # Check if the point (x, y) is inside, outside or on the boundary of the polygon
    n = len(polygon)
    if n < 3:
        return "OUTSIDE"
    
    count = 0
    for i in range(n):
        x1, y1 = polygon[i]
        x2, y2 = polygon[(i + 1) % n]
        
        if on_boundary(x1, y1, x2, y2, x, y):
            return "BOUNDARY"
        
        if y1 <= y and y2 > y or y2 <= y and y1 > y:
            if orientation(x1, y1, x2, y2, x, y) == 0:
                return "BOUNDARY"
            if orientation(x1, y1, x2, y2, x, y) == 1:
                count += 1
    
    if count % 2 == 1:
        return "INSIDE"
    else:
        return "OUTSIDE"

# Read input
n, m = map(int, input().split())
polygon = []
for _ in range(n):
    x, y = map(int, input().split())
    polygon.append((x, y))
points = []
for _ in range(m):
    x, y = map(int, input().split())
    points.append((x, y))

# Process each point
for point in points:
    x, y = point
    result = inside_polygon(polygon, x, y)
    print(result)
