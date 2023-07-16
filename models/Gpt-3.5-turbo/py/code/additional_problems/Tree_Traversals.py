
def build_postorder(preorder, inorder):
    if len(preorder) == 0:
        return []
    
    root = preorder[0]
    idx = inorder.index(root)
    
    left_subtree_preorder = preorder[1:idx+1]
    left_subtree_inorder = inorder[:idx]
    right_subtree_preorder = preorder[idx+1:]
    right_subtree_inorder = inorder[idx+1:]
    
    left_subtree_postorder = build_postorder(left_subtree_preorder, left_subtree_inorder)
    right_subtree_postorder = build_postorder(right_subtree_preorder, right_subtree_inorder)
    
    return left_subtree_postorder + right_subtree_postorder + [root]

# Read input
n = int(input())
preorder = list(map(int, input().split()))
inorder = list(map(int, input().split()))

# Call the function and print the result
postorder = build_postorder(preorder, inorder)
print(' '.join(map(str, postorder)))


def build_postorder(preorder, inorder):
    def build_postorder_helper(pre_start, pre_end, in_start, in_end):
        if pre_start > pre_end:
            return []
        
        root = preorder[pre_start]
        idx = index_map[root]
        
        left_subtree_size = idx - in_start
        right_subtree_size = in_end - idx
        
        left_subtree_postorder = build_postorder_helper(pre_start + 1, pre_start + left_subtree_size, in_start, idx - 1)
        right_subtree_postorder = build_postorder_helper(pre_start + left_subtree_size + 1, pre_end, idx + 1, in_end)
        
        return left_subtree_postorder + right_subtree_postorder + [root]
    
    index_map = {val: idx for idx, val in enumerate(inorder)}
    return build_postorder_helper(0, n - 1, 0, n - 1)
