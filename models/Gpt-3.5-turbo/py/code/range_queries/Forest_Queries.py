
# read input
n, q = map(int, input().split())
forest = [input() for _ in range(n)]
queries = [list(map(int, input().split())) for _ in range(q)]

# calculate the number of trees in each prefix rectangle
prefix_trees = [[0] * (n+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, n+1):
        prefix_trees[i][j] = prefix_trees[i-1][j] + prefix_trees[i][j-1] - prefix_trees[i-1][j-1]
        if forest[i-1][j-1] == '*':
            prefix_trees[i][j] += 1

# process queries
for query in queries:
    y1, x1, y2, x2 = query
    trees_in_query = prefix_trees[y2][x2] - prefix_trees[y1-1][x2] - prefix_trees[y2][x1-1] + prefix_trees[y1-1][x1-1]
    print(trees_in_query)
