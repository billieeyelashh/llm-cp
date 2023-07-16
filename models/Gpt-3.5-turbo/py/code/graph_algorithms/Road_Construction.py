
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x != y:
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]

def solve(n, m, roads):
    dsu = DSU(n)
    components = n
    max_component_size = 1
    result = []

    for road in roads:
        a, b = road
        if dsu.find(a-1) != dsu.find(b-1):
            dsu.union(a-1, b-1)
            components -= 1
            max_component_size = max(max_component_size, dsu.size[dsu.find(a-1)])
        result.append((components, max_component_size))

    return result

# Read input
n, m = map(int, input().split())
roads = [list(map(int, input().split())) for _ in range(m)]

# Solve the problem
result = solve(n, m, roads)

# Print the result
for component, max_size in result:
    print(component, max_size)
