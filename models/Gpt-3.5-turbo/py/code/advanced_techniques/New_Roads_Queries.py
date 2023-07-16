
# Function to find the parent of a node in the disjoint set
def find_parent(parent, x):
    if parent[x] == x:
        return x
    parent[x] = find_parent(parent, parent[x])
    return parent[x]

# Function to merge two sets in the disjoint set
def union(parent, rank, x, y):
    x_parent = find_parent(parent, x)
    y_parent = find_parent(parent, y)

    if rank[x_parent] < rank[y_parent]:
        parent[x_parent] = y_parent
    elif rank[x_parent] > rank[y_parent]:
        parent[y_parent] = x_parent
    else:
        parent[y_parent] = x_parent
        rank[x_parent] += 1

# Function to process the queries
def process_queries(n, m, q, roads, queries):
    parent = [i for i in range(n+1)]
    rank = [0] * (n+1)

    # Merge the sets based on the roads
    for road in roads:
        a, b = road
        union(parent, rank, a, b)

    # Process the queries
    for query in queries:
        a, b = query
        a_parent = find_parent(parent, a)
        b_parent = find_parent(parent, b)

        # If the two cities have the same parent, they are connected
        if a_parent == b_parent:
            print(0)
        else:
            print(-1)

# Read the input
n, m, q = map(int, input().split())
roads = []
for _ in range(m):
    a, b = map(int, input().split())
    roads.append((a, b))
queries = []
for _ in range(q):
    a, b = map(int, input().split())
    queries.append((a, b))

# Process the queries
process_queries(n, m, q, roads, queries)
