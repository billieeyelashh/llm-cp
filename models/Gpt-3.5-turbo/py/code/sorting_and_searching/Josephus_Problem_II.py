
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def solve(n, k):
    # Create a circular linked list with values from 1 to n
    head = Node(1)
    curr = head
    for i in range(2, n+1):
        curr.next = Node(i)
        curr = curr.next
    curr.next = head

    # Iterate until there is only one node left
    while curr.next != curr:
        # Skip k-1 nodes
        for _ in range(k-1):
            curr = curr.next
        # Remove the k-th node
        curr.next = curr.next.next

    # Print the removal order
    removal_order = []
    while curr.next != curr:
        removal_order.append(curr.next.value)
        curr = curr.next
    removal_order.append(curr.value)
    print(' '.join(map(str, removal_order)))

# Read input values
n, k = map(int, input().split())

# Solve the problem
solve(n, k)
