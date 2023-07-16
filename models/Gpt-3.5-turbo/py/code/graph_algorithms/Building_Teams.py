
from collections import defaultdict

def dfs(node, color, graph, colors):
    colors[node] = color
    for neighbor in graph[node]:
        if colors[neighbor] == 0:
            dfs(neighbor, 3 - color, graph, colors)

def divide_teams(n, m, friendships):
    graph = defaultdict(list)
    for a, b in friendships:
        graph[a].append(b)
        graph[b].append(a)

    colors = [0] * (n+1)
    for i in range(1, n+1):
        if colors[i] == 0:
            dfs(i, 1, graph, colors)

    return colors[1:]

# Read input
n, m = map(int, input().split())
friendships = [list(map(int, input().split())) for _ in range(m)]

# Divide teams
teams = divide_teams(n, m, friendships)

# Print the teams
if 0 in teams:
    print("IMPOSSIBLE")
else:
    print(*teams)
