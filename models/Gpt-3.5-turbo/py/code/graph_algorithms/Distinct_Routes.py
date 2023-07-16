
def dfs(curr_room, visited):
    # Base case: if we reach room n, return 1 (indicating that we can complete the game)
    if curr_room == n:
        return 1

    # Initialize the maximum number of days to 0
    max_days = 0

    # Iterate through all teleporters starting from the current room
    for i in range(len(teleporters)):
        teleporter = teleporters[i]
        if teleporter[0] == curr_room and i not in visited:
            # Mark the teleporter as visited
            visited.append(i)

            # Recursively explore the next room using the teleporter
            days = dfs(teleporter[1], visited)

            # Update the maximum number of days
            max_days = max(max_days, days)

            # Backtrack: unmark the teleporter as visited
            visited.pop()

    # Return the maximum number of days
    return max_days


# Read the input
n, m = map(int, input().split())

# Initialize the teleporters list
teleporters = []

# Read the teleporters
for _ in range(m):
    a, b = map(int, input().split())
    teleporters.append((a, b))

# Call the DFS function with the initial room number and an empty visited list
max_days = dfs(1, [])

# Print the maximum number of days
print(max_days)


def dfs(curr_room, visited, route):
    # Base case: if we reach room n, return 1 (indicating that we can complete the game)
    if curr_room == n:
        return 1

    # Initialize the maximum number of days and the best route
    max_days = 0
    best_route = []

    # Iterate through all teleporters starting from the current room
    for i in range(len(teleporters)):
        teleporter = teleporters[i]
        if teleporter[0] == curr_room and i not in visited:
            # Mark the teleporter as visited
            visited.append(i)

            # Recursively explore the next room using the teleporter
            days = dfs(teleporter[1], visited, route + [curr_room])

            # Update the maximum number of days and the best route
            if days > max_days:
                max_days = days
                best_route = route + [curr_room]

            # Backtrack: unmark the teleporter as visited
            visited.pop()

    # Return the maximum number of days and the best route
    return max_days, best_route


# Call the DFS function with the initial room number, an empty visited list, and an empty route
max_days, best_route = dfs(1, [], [])

# Print the maximum number of days
print(max_days)

# Print the best route
for room in best_route:
    print(room, end=' ')
print(n)
