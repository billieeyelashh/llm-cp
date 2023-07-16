
import sys

def hungarian(cost_matrix):
    n = len(cost_matrix)
    INF = sys.maxsize

    def reduce(cost_matrix):
        for i in range(n):
            min_val = min(cost_matrix[i])
            for j in range(n):
                cost_matrix[i][j] -= min_val

        for j in range(n):
            min_val = INF
            for i in range(n):
                min_val = min(min_val, cost_matrix[i][j])
            for i in range(n):
                cost_matrix[i][j] -= min_val

    def dfs(u, assignment, visited):
        for v in range(n):
            if not visited[v] and cost_matrix[u][v] == 0:
                visited[v] = True
                if assignment[v] == -1 or dfs(assignment[v], assignment, visited):
                    assignment[v] = u
                    return True
        return False

    assignment = [-1] * n
    for i in range(n):
        while True:
            visited = [False] * n
            if dfs(i, assignment, visited):
                break
            else:
                reduce(cost_matrix)

    return assignment

# Read input
n = int(input())
cost_matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    cost_matrix.append(row)

# Solve using Hungarian algorithm
assignment = hungarian(cost_matrix)

# Calculate minimum total cost
min_cost = sum(cost_matrix[i][assignment[i]] for i in range(n))

# Print minimum total cost
print(min_cost)

# Print assignments
for i in range(n):
    print(i+1, assignment[i]+1)
