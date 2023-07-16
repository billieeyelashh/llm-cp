
def calculate_subordinates(n, bosses):
    # Construct the adjacency list representation of the company structure
    graph = [[] for _ in range(n + 1)]
    for i in range(2, n + 1):
        graph[bosses[i - 2]].append(i)

    # Initialize the result array
    subordinates = [0] * (n + 1)

    # Perform DFS traversal starting from the general director (employee 1)
    def dfs(node):
        count = 1  # Include the current employee in the count
        for neighbor in graph[node]:
            count += dfs(neighbor)
        subordinates[node] = count
        return count

    dfs(1)

    # Return the result array without including the general director (employee 1)
    return subordinates[1:]

# Read the input
n = int(input())
bosses = list(map(int, input().split()))

# Calculate the number of subordinates for each employee
result = calculate_subordinates(n, bosses)

# Print the result
print(*result)
