
class Node:
    def __init__(self, start, end):
        self.start = start   # starting index of the range
        self.end = end       # ending index of the range
        self.min_price = float('inf')  # minimum pizza price within the range
        self.left = None     # left child node
        self.right = None    # right child node


def build_segment_tree(arr, start, end):
    if start == end:
        node = Node(start, end)
        node.min_price = arr[start]
        return node
    
    mid = (start + end) // 2
    left_child = build_segment_tree(arr, start, mid)
    right_child = build_segment_tree(arr, mid + 1, end)
    
    node = Node(start, end)
    node.left = left_child
    node.right = right_child
    node.min_price = min(left_child.min_price, right_child.min_price)
    
    return node


def update_segment_tree(node, index, new_price):
    if node.start == node.end:
        node.min_price = new_price
        return
    
    mid = (node.start + node.end) // 2
    if index <= mid:
        update_segment_tree(node.left, index, new_price)
    else:
        update_segment_tree(node.right, index, new_price)
        
    node.min_price = min(node.left.min_price, node.right.min_price)


def query_segment_tree(node, start, end):
    if start > node.end or end < node.start:
        return float('inf')
    
    if start <= node.start and end >= node.end:
        return node.min_price
    
    return min(query_segment_tree(node.left, start, end), query_segment_tree(node.right, start, end))


n, q = map(int, input().split())
prices = list(map(int, input().split()))

# Build the segment tree
root = build_segment_tree(prices, 0, n-1)

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        # Update pizza price
        update_segment_tree(root, query[1] - 1, query[2])
    else:
        # Query minimum pizza price within a range
        start, end = query[1] - 1, query[1] - 1
        min_price = query_segment_tree(root, start, end)
        print(min_price)
