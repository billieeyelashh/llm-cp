
def build_segment_tree(arr, tree, node, start, end):
    # Base case: leaf node
    if start == end:
        tree[node] = arr[start]
        return

    # Recursive case: build left and right subtrees
    mid = (start + end) // 2
    build_segment_tree(arr, tree, 2 * node, start, mid)
    build_segment_tree(arr, tree, 2 * node + 1, mid + 1, end)

    # Combine information from left and right subtrees
    tree[node] = min(tree[2 * node], tree[2 * node + 1])

def update_segment_tree(arr, tree, node, start, end, idx, val):
    # Base case: leaf node
    if start == end:
        arr[idx] = val
        tree[node] = val
        return

    # Recursive case: update left or right subtree
    mid = (start + end) // 2
    if start <= idx <= mid:
        update_segment_tree(arr, tree, 2 * node, start, mid, idx, val)
    else:
        update_segment_tree(arr, tree, 2 * node + 1, mid + 1, end, idx, val)

    # Update information in current node
    tree[node] = min(tree[2 * node], tree[2 * node + 1])

def query_segment_tree(tree, node, start, end, left, right):
    # Base case: query range is completely outside node's range
    if start > right or end < left:
        return float('inf')

    # Base case: node's range is completely inside query range
    if left <= start and end <= right:
        return tree[node]

    # Recursive case: query range overlaps with node's range
    mid = (start + end) // 2
    left_min = query_segment_tree(tree, 2 * node, start, mid, left, right)
    right_min = query_segment_tree(tree, 2 * node + 1, mid + 1, end, left, right)
    return min(left_min, right_min)

# Read input
n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Build segment tree
tree = [0] * (4 * n)
build_segment_tree(arr, tree, 1, 0, n - 1)

# Process queries
for _ in range(q):
    query_type, param1, param2 = map(int, input().split())
    if query_type == 1:
        update_segment_tree(arr, tree, 1, 0, n - 1, param1 - 1, param2)
    else:
        result = query_segment_tree(tree, 1, 0, n - 1, param1 - 1, param2 - 1)
        print(result)
