
from collections import defaultdict, deque

# Step 1
n, m = map(int, input().split())

# Step 2
adj_list = defaultdict(list)

# Step 3
for _ in range(m):
    a, b = map(int, input().split())
    adj_list[a].append(b)

# Step 4
indegree = [0] * (n+1)

# Step 5
for a in adj_list:
    for b in adj_list[a]:
        indegree[b] += 1

# Step 6
queue = deque()

# Step 7
for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

# Step 8
result = []
while queue:
    curr = queue.popleft()
    result.append(curr)

    for next_course in adj_list[curr]:
        indegree[next_course] -= 1
        if indegree[next_course] == 0:
            queue.append(next_course)

# Step 9
print(' '.join(map(str, result)))
