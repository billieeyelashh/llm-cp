
def build_segment_tree(arr, tree, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        build_segment_tree(arr, tree, 2 * node, start, mid)
        build_segment_tree(arr, tree, 2 * node + 1, mid + 1, end)
        tree[node] = max(tree[2 * node], tree[2 * node + 1])

def update_segment_tree(arr, tree, node, start, end, idx, val):
    if start == end:
        arr[idx] = val
        tree[node] = val
    else:
        mid = (start + end) // 2
        if start <= idx <= mid:
            update_segment_tree(arr, tree, 2 * node, start, mid, idx, val)
        else:
            update_segment_tree(arr, tree, 2 * node + 1, mid + 1, end, idx, val)
        tree[node] = max(tree[2 * node], tree[2 * node + 1])

def query_segment_tree(tree, node, start, end, left, right):
    if start > right or end < left:
        return float('-inf')
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    left_sum = query_segment_tree(tree, 2 * node, start, mid, left, right)
    right_sum = query_segment_tree(tree, 2 * node + 1, mid + 1, end, left, right)
    return max(left_sum, right_sum)

n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Build the segment tree
tree = [0] * (4 * n)
build_segment_tree(arr, tree, 1, 0, n - 1)

# Process the queries
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        k, u = query[1], query[2]
        update_segment_tree(arr, tree, 1, 0, n - 1, k - 1, u)
    else:
        a, b = query[1], query[2]
        result = query_segment_tree(tree, 1, 0, n - 1, a - 1, b - 1)
        print(result)
