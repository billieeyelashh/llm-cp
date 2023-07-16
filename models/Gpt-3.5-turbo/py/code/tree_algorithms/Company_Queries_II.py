
def find_lowest_common_boss(n, q, hierarchy, queries):
    parent = [0] * (n + 1)

    # Build the parent array
    for i in range(2, n + 1):
        parent[i] = hierarchy[i - 2]

    def find_parent(employee):
        if parent[employee] == 0:
            return employee
        return find_parent(parent[employee])

    # Process each query
    for a, b in queries:
        parent_a = find_parent(a)
        parent_b = find_parent(b)

        # Find the lowest common boss
        while parent_a != parent_b:
            if parent_a > parent_b:
                parent_a = find_parent(parent_a)
            else:
                parent_b = find_parent(parent_b)

        print(parent_a)

# Read input
n, q = map(int, input().split())
hierarchy = list(map(int, input().split()))
queries = [map(int, input().split()) for _ in range(q)]

# Solve the problem
find_lowest_common_boss(n, q, hierarchy, queries)
