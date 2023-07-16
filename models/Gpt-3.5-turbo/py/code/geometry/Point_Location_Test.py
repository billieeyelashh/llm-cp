
def orientation(x1, y1, x2, y2, x3, y3):
    # Compute the cross product of vectors p2p1 and p2p3
    cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2)
    
    if cross_product > 0:
        return "LEFT"
    elif cross_product < 0:
        return "RIGHT"
    else:
        return "TOUCH"

# Read the number of tests
t = int(input())

for _ in range(t):
    # Read the coordinates for each test
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    
    # Print the result for each test
    print(orientation(x1, y1, x2, y2, x3, y3))
