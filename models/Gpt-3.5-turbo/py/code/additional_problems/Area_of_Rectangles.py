
n = int(input())
rectangles = []
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    rectangles.append((x1, y1, x2, y2))

x = sorted(set(x1 for (x1, _, x2, _) in rectangles) | set(x2 for (_, _, x2, _) in rectangles))
y = sorted(set(y1 for (_, y1, _, _) in rectangles) | set(y2 for (_, _, _, y2) in rectangles))

total_area = 0
for i in range(len(x) - 1):
    current_height = 0
    previous_y = y[0]
    for j in range(len(y) - 1):
        if current_height > 0:
            total_area += (y[j + 1] - previous_y)
        previous_y = y[j + 1]
        for (x1, y1, x2, y2) in rectangles:
            if x1 <= x[i] and x[i + 1] <= x2 and y1 <= y[j] and y[j + 1] <= y2:
                current_height = max(current_height, y2 - y1)
                break
    if current_height > 0:
        total_area += (y[-1] - previous_y)

print(total_area)
