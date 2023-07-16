
from collections import defaultdict

# Function to perform depth-first search (DFS)
def dfs(course, adj_list, visited, stack):
    visited[course] = True
    for adj_course in adj_list[course]:
        if not visited[adj_course]:
            dfs(adj_course, adj_list, visited, stack)
    stack.append(course)

# Read the input values of n and m
n, m = map(int, input().split())

# Create an adjacency list to represent the directed graph
adj_list = defaultdict(list)

# Read the m requirements and add the corresponding edges to the adjacency list
for _ in range(m):
    a, b = map(int, input().split())
    adj_list[a].append(b)

# Initialize visited array and stack
visited = [False] * (n + 1)
stack = []

# Perform depth-first search on each course
for course in range(1, n + 1):
    if not visited[course]:
        dfs(course, adj_list, visited, stack)

# If stack is empty, print "IMPOSSIBLE"
if not stack:
    print("IMPOSSIBLE")
else:
    # Print the courses in reverse order from the stack
    while stack:
        print(stack.pop(), end=' ')
