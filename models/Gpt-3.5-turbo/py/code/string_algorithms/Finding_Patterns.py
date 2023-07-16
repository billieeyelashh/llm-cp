
# Implementation of Aho-Corasick algorithm

class AhoCorasickNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_pattern = False
        self.fail_link = None

def build_trie(patterns):
    root = AhoCorasickNode()
    for pattern in patterns:
        current_node = root
        for char in pattern:
            if char not in current_node.children:
                current_node.children[char] = AhoCorasickNode()
            current_node = current_node.children[char]
        current_node.is_end_of_pattern = True
    return root

def build_fail_links(root):
    queue = []
    for child in root.children.values():
        queue.append((root, child))
    
    while queue:
        parent, current_node = queue.pop(0)
        for char, child in current_node.children.items():
            queue.append((current_node, child))
            fail_node = parent.fail_link
            while fail_node is not None and char not in fail_node.children:
                fail_node = fail_node.fail_link
            current_node.children[char].fail_link = fail_node.children.get(char, root)

def search_patterns(string, patterns):
    root = build_trie(patterns)
    build_fail_links(root)
    
    current_node = root
    results = []
    for char in string:
        while current_node is not None and char not in current_node.children:
            current_node = current_node.fail_link
        if current_node is None:
            current_node = root
            continue
        current_node = current_node.children[char]
        if current_node.is_end_of_pattern:
            results.append("YES")
    
    return results

# Main function
def solve():
    string = input().strip()
    k = int(input())
    patterns = []
    for _ in range(k):
        patterns.append(input().strip())
    
    results = search_patterns(string, patterns)
    for result in results:
        print(result)

# Run the main function
solve()
