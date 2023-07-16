
def construct_path(n, m, y1, x1, y2, x2):
    # Check if the grid has more than one row or more than one column
    if n == 1 or m == 1:
        return 'NO'

    # Construct the path
    path = ''
    if y1 < y2:
        path += 'D' * (y2 - y1)
    elif y1 > y2:
        path += 'U' * (y1 - y2)
    
    if x1 < x2:
        path += 'R' * (x2 - x1)
    elif x1 > x2:
        path += 'L' * (x1 - x2)
    
    return 'YES\n' + path

# Read the number of tests
t = int(input())

# Process each test case
for _ in range(t):
    # Read the input for each test case
    n, m, y1, x1, y2, x2 = map(int, input().split())

    # Call the function to construct the path and print the result
    print(construct_path(n, m, y1, x1, y2, x2))
