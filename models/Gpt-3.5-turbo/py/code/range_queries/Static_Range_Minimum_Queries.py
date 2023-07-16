
def build_segment_tree(arr, tree, i, left, right):
    if left == right:
        tree[i] = arr[left]
    else:
        mid = (left + right) // 2
        build_segment_tree(arr, tree, 2*i, left, mid)
        build_segment_tree(arr, tree, 2*i + 1, mid + 1, right)
        tree[i] = min(tree[2*i], tree[2*i + 1])

def query_segment_tree(tree, i, left, right, query_left, query_right):
    if right < query_left or left > query_right:
        return float('inf')
    elif left >= query_left and right <= query_right:
        return tree[i]
    else:
        mid = (left + right) // 2
        left_result = query_segment_tree(tree, 2*i, left, mid, query_left, query_right)
        right_result = query_segment_tree(tree, 2*i + 1, mid + 1, right, query_left, query_right)
        return min(left_result, right_result)

n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Construct the segment tree
tree = [0] * (4*n)
build_segment_tree(arr, tree, 1, 0, n-1)

# Process the queries
for _ in range(q):
    a, b = map(int, input().split())
    result = query_segment_tree(tree, 1, 0, n-1, a-1, b-1)
    print(result)
