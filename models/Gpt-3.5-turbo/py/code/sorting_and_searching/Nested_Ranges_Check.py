
class Range:
    def __init__(self, start, end, index):
        self.start = start
        self.end = end
        self.index = index

n = int(input())
ranges = []
contains = [0] * n
contained_by = [0] * n
stack = []

for i in range(n):
    start, end = map(int, input().split())
    ranges.append(Range(start, end, i))

for i in range(n):
    while stack and ranges[i].end > ranges[stack[-1]].end:
        contains[ranges[stack.pop()].index] = 1

    if stack:
        contained_by[ranges[i].index] = 1

    stack.append(i)

print(' '.join(map(str, contains)))
print(' '.join(map(str, contained_by)))
