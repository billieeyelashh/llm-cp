
class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.size[root_x] < self.size[root_y]:
                root_x, root_y = root_y, root_x
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]

def solve(n, m, nums, swaps):
    dsu = DSU(n)
    rounds = 0
    result = []
    for a, b in swaps:
        root_a = dsu.find(a)
        root_b = dsu.find(b)
        if root_a != root_b:
            dsu.union(root_a, root_b)
            rounds += 1
        result.append(rounds)
    return result

# Read input
n, m = map(int, input().split())
nums = list(map(int, input().split()))
swaps = [tuple(map(int, input().split())) for _ in range(m)]

# Solve and print output
for rounds in solve(n, m, nums, swaps):
    print(rounds)
