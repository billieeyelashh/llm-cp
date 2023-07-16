
class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [0] * (4 * len(arr))  # segment tree array
    
    def build(self, node, start, end):
        if start == end:
            self.tree[node] = self.arr[start]
        else:
            mid = (start + end) // 2
            self.build(2 * node, start, mid)
            self.build(2 * node + 1, mid + 1, end)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]
    
    def update(self, node, start, end, idx, val):
        if start == end:
            self.arr[idx] = val
            self.tree[node] = val
        else:
            mid = (start + end) // 2
            if start <= idx <= mid:
                self.update(2 * node, start, mid, idx, val)
            else:
                self.update(2 * node + 1, mid + 1, end, idx, val)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]
    
    def query(self, node, start, end, left, right):
        if start > right or end < left:
            return 0
        if left <= start and end <= right:
            return self.tree[node]
        mid = (start + end) // 2
        sum_left = self.query(2 * node, start, mid, left, right)
        sum_right = self.query(2 * node + 1, mid + 1, end, left, right)
        return sum_left + sum_right

n, q = map(int, input().split())
arr = list(map(int, input().split()))

tree = SegmentTree(arr)
tree.build(1, 0, n - 1)

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        k, a, x = query[1:]
        tree.update(1, 0, n - 1, a - 1, x)
    elif query[0] == 2:
        k, a, b = query[1:]
        print(tree.query(1, 0, n - 1, a - 1, b - 1))
    else:
        k = query[1]
        arr.append(arr[k - 1])
        tree.build(1, 0, n - 1)
