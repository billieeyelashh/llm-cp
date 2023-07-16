
def orientation(x1, y1, x2, y2, x3, y3):
    return (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1)

def intersect(x1, y1, x2, y2, x3, y3, x4, y4):
    orientation1 = orientation(x1, y1, x2, y2, x3, y3)
    orientation2 = orientation(x1, y1, x2, y2, x4, y4)
    orientation3 = orientation(x3, y3, x4, y4, x1, y1)
    orientation4 = orientation(x3, y3, x4, y4, x2, y2)
    
    if (orientation1 > 0 and orientation2 < 0) or (orientation1 < 0 and orientation2 > 0):
        return True
    if (orientation3 > 0 and orientation4 < 0) or (orientation3 < 0 and orientation4 > 0):
        return True
    
    if orientation1 == 0 and on_segment(x1, y1, x2, y2, x3, y3):
        return True
    if orientation2 == 0 and on_segment(x1, y1, x2, y2, x4, y4):
        return True
    if orientation3 == 0 and on_segment(x3, y3, x4, y4, x1, y1):
        return True
    if orientation4 == 0 and on_segment(x3, y3, x4, y4, x2, y2):
        return True
    
    return False

def on_segment(x1, y1, x2, y2, x, y):
    if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
        return True
    return False

# Reading input
t = int(input())
for _ in range(t):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    
    # Checking if the line segments intersect
    if intersect(x1, y1, x2, y2, x3, y3, x4, y4):
        print("YES")
    else:
        print("NO")
