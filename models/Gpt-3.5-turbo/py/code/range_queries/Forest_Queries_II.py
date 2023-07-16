
def solve(n, q, forest, queries):
    # Initialize the prefix sum array
    prefix_sum = [[0] * (n + 1) for _ in range(n + 1)]

    # Calculate the prefix sum array
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1]
            if forest[i - 1][j - 1] == '*':
                prefix_sum[i][j] += 1

    # Process each query
    for query in queries:
        if query[0] == 1:
            # Change the state of a square
            y, x = query[1], query[2]
            if forest[y - 1][x - 1] == '.':
                prefix_sum[y][x] += 1
                forest[y - 1][x - 1] = '*'
            else:
                prefix_sum[y][x] -= 1
                forest[y - 1][x - 1] = '.'
        else:
            # Count the number of trees in a rectangle
            y1, x1, y2, x2 = query[1], query[2], query[3], query[4]
            result = prefix_sum[y2][x2] - prefix_sum[y1 - 1][x2] - prefix_sum[y2][x1 - 1] + prefix_sum[y1 - 1][x1 - 1]
            print(result)

# Read the input
n, q = map(int, input().split())
forest = [list(input().strip()) for _ in range(n)]
queries = []
for _ in range(q):
    query = list(map(int, input().split()))
    queries.append(query)

# Solve the problem
solve(n, q, forest, queries)
