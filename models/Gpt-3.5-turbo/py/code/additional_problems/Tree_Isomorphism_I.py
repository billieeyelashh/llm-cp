
def isomorphic(tree1, tree2):
    # Base case: if both trees are empty, they are isomorphic
    if not tree1 and not tree2:
        return True
    
    # If one of the trees is empty while the other is not, they cannot be isomorphic
    if not tree1 or not tree2:
        return False
    
    # Check if the root nodes have the same number of children
    if len(tree1) != len(tree2):
        return False
    
    # Recursively check if the subtrees rooted at each child node are isomorphic
    for i in range(len(tree1)):
        if not isomorphic(tree1[i], tree2[i]):
            return False
    
    return True

# Read the number of tests
t = int(input())

# Perform the tests
for _ in range(t):
    # Read the number of nodes
    n = int(input())
    
    # Initialize the trees as lists of empty lists
    tree1 = [[] for _ in range(n)]
    tree2 = [[] for _ in range(n)]
    
    # Read the edges of the first tree
    for _ in range(n-1):
        a, b = map(int, input().split())
        tree1[a-1].append(b-1)
    
    # Read the edges of the second tree
    for _ in range(n-1):
        a, b = map(int, input().split())
        tree2[a-1].append(b-1)
    
    # Check if the trees are isomorphic and print the result
    if isomorphic(tree1, tree2):
        print("YES")
    else:
        print("NO")
