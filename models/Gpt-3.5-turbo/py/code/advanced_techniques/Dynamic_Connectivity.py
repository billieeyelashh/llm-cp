
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_components = n

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.size[root_x] < self.size[root_y]:
                root_x, root_y = root_y, root_x
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]
            self.num_components -= 1

    def get_num_components(self):
        return self.num_components


def count_components(n, edges, events):
    uf = UnionFind(n)
    result = [uf.get_num_components()]

    for a, b in edges:
        uf.union(a-1, b-1)
        result.append(uf.get_num_components())

    for t, a, b in events:
        if t == 1:
            uf.union(a-1, b-1)
        else:
            if uf.find(a-1) == uf.find(b-1):
                uf.union(a-1, b-1)
        result.append(uf.get_num_components())

    return result


# Read input
n, m, k = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]
events = [tuple(map(int, input().split())) for _ in range(k)]

# Solve the problem
result = count_components(n, edges, events)

# Print the result
print(' '.join(map(str, result)))
