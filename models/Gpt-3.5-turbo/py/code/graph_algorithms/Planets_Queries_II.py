
def dfs(curr_planet, destination, teleporters, visited):
    # If we have reached the destination planet, return 0
    if curr_planet == destination:
        return 0
    
    # If we have already visited this planet, return -1
    if visited[curr_planet]:
        return -1
    
    # Mark the current planet as visited
    visited[curr_planet] = True
    
    # Recursively explore all possible teleportations
    next_planet = teleporters[curr_planet]
    result = dfs(next_planet, destination, teleporters, visited)
    
    # If no valid path is found, return -1
    if result == -1:
        return -1
    
    # Add 1 to the minimum number of teleportations
    return result + 1

# Read the input
n, q = map(int, input().split())
teleporters = list(map(int, input().split()))

# Process the queries
for _ in range(q):
    a, b = map(int, input().split())
    
    # Initialize the visited array
    visited = [False] * (n + 1)
    
    # Find the minimum number of teleportations
    result = dfs(a, b, teleporters, visited)
    
    # Print the result
    print(result)
