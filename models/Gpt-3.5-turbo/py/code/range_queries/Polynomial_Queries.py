
class SegmentTree:
    def __init__(self, n):
        self.size = 1 << (n - 1).bit_length()
        self.tree = [0] * (2 * self.size)

    def update(self, a, b):
        a += self.size
        b += self.size
        while a <= b:
            if a % 2 == 1:
                self.tree[a] += a - self.size + 1
                a += 1
            if b % 2 == 0:
                self.tree[b] += b - self.size + 1
                b -= 1
            a //= 2
            b //= 2

    def query(self, a, b):
        a += self.size
        b += self.size
        result = 0
        while a <= b:
            if a % 2 == 1:
                result += self.tree[a]
                a += 1
            if b % 2 == 0:
                result += self.tree[b]
                b -= 1
            a //= 2
            b //= 2
        return result


# Read input
n, q = map(int, input().split())
t = list(map(int, input().split()))

# Build segment tree
segment_tree = SegmentTree(n)
for i in range(n):
    segment_tree.tree[segment_tree.size + i] = t[i]
for i in range(segment_tree.size - 1, 0, -1):
    segment_tree.tree[i] = segment_tree.tree[2 * i] + segment_tree.tree[2 * i + 1]

# Process queries
for _ in range(q):
    query_type, a, b = map(int, input().split())
    if query_type == 1:
        segment_tree.update(a - 1, b - 1)
    else:
        print(segment_tree.query(a - 1, b - 1))
