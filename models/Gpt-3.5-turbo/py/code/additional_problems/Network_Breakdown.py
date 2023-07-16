
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a != b:
        parent[b] = a

def count_components(n, connections, breakdowns):
    parent = [i for i in range(n+1)]  # Initialize parent array
    components = []  # List to store the count of components after each breakdown

    # Union operation for connections
    for a, b in connections:
        union(parent, a, b)

    # Count components after each breakdown
    for a, b in reversed(breakdowns):
        union(parent, a, b)
        components.append(len(set(find_parent(parent, i) for i in range(1, n+1))))

    return components[::-1]  # Reverse the list of components

# Read input
n, m, k = map(int, input().split())
connections = [tuple(map(int, input().split())) for _ in range(m)]
breakdowns = [tuple(map(int, input().split())) for _ in range(k)]

# Calculate and print the number of components after each breakdown
for count in count_components(n, connections, breakdowns):
    print(count, end=' ')
