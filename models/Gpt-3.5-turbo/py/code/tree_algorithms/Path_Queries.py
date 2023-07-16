
def update(tree, i, x):
    while i < len(tree):
        tree[i] += x
        i += i & -i

def query(tree, i):
    result = 0
    while i > 0:
        result += tree[i]
        i -= i & -i
    return result

n, q = map(int, input().split())
values = list(map(int, input().split()))
edges = [list(map(int, input().split())) for _ in range(n-1)]
queries = [list(map(int, input().split())) for _ in range(q)]

tree = [0] * (n+1)

# Build the tree
for a, b in edges:
    update(tree, b, values[b-1])

# Process queries
for query_type, s, *args in queries:
    if query_type == 1:
        x = args[0]
        update(tree, s, x - values[s-1])
        values[s-1] = x
    elif query_type == 2:
        result = query(tree, s)
        print(result + values[0])
