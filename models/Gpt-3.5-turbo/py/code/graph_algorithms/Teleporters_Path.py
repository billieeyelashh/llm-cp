
def solve(n, m, teleporters):
    adj_list = {i: [] for i in range(1, n + 1)}
    for a, b in teleporters:
        adj_list[a].append(b)

    stack = [1]
    visited = {1}

    while stack:
        level = stack.pop()

        if level == n:
            return visited

        for adj_level in adj_list[level]:
            if adj_level not in visited:
                stack.append(adj_level)
                visited.add(adj_level)
                break
        else:
            visited.remove(level)

    return "IMPOSSIBLE"

# Read input
n, m = map(int, input().split())
teleporters = [list(map(int, input().split())) for _ in range(m)]

# Solve the problem
result = solve(n, m, teleporters)

# Print the result
if result == "IMPOSSIBLE":
    print(result)
else:
    print(" ".join(map(str, result)))
