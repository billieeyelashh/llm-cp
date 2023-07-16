
n = int(input())
segments = []
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    segments.append((x1, y1, x2, y2))


points = []


for x1, y1, x2, y2 in segments:
    points.append(y1)
    points.append(y2)


points.sort()


count = 0


active_segments = set()


for y in points:


    intersections = []


    for x1, y1, x2, y2 in segments:
        if y1 <= y <= y2:
            intersections.append(x1 + (x2 - x1) * (y - y1) / (y2 - y1))


    intersections.sort()


    for i in range(len(intersections) - 1):


        if intersections[i] != segments[i][0] and intersections[i] != segments[i][2]:


            count += 1


        if y == segments[i][1]:
            active_segments.add(i)
        if y == segments[i][3]:
            active_segments.remove(i)


print(count)
