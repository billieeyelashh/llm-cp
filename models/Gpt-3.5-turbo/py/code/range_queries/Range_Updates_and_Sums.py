
class SegmentTree:
    def __init__(self, n):
        self.size = 4 * n
        self.tree = [0] * self.size
    
    def build(self, arr, v, tl, tr):
        if tl == tr:
            self.tree[v] = arr[tl]
        else:
            tm = (tl + tr) // 2
            self.build(arr, 2 * v, tl, tm)
            self.build(arr, 2 * v + 1, tm + 1, tr)
            self.tree[v] = self.tree[2 * v] + self.tree[2 * v + 1]
    
    def update(self, v, tl, tr, l, r, add, set_val):
        if l > r:
            return
        if l == tl and r == tr:
            if set_val is not None:
                self.tree[v] = (r - l + 1) * set_val
            else:
                self.tree[v] += (r - l + 1) * add
        else:
            tm = (tl + tr) // 2
            self.update(2 * v, tl, tm, l, min(r, tm), add, set_val)
            self.update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add, set_val)
            self.tree[v] = self.tree[2 * v] + self.tree[2 * v + 1]
    
    def query(self, v, tl, tr, l, r):
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.tree[v]
        tm = (tl + tr) // 2
        left_sum = self.query(2 * v, tl, tm, l, min(r, tm))
        right_sum = self.query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
        return left_sum + right_sum


# Read input
n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Build the segment tree
st = SegmentTree(n)
st.build(arr, 1, 0, n - 1)

# Process queries
for _ in range(q):
    query_type, a, b, *args = map(int, input().split())
    if query_type == 1:
        x = args[0]
        st.update(1, 0, n - 1, a - 1, b - 1, x, None)
    elif query_type == 2:
        x = args[0]
        st.update(1, 0, n - 1, a - 1, b - 1, 0, x)
    else:
        result = st.query(1, 0, n - 1, a - 1, b - 1)
        print(result)
