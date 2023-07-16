
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

def insert(root, word):
    node = root
    for char in word:
        if char not in node.children:
            node.children[char] = TrieNode()
        node = node.children[char]
    node.is_end_of_word = True

def count_distinct_substrings(string):
    root = TrieNode()
    n = len(string)
    count = 0
    
    for i in range(n):
        node = root
        for j in range(i, n):
            char = string[j]
            if char not in node.children:
                node.children[char] = TrieNode()
                count += 1
            node = node.children[char]
            
            if node.is_end_of_word:
                break
        node.is_end_of_word = True
    
    return count

# Driver code
string = input()
print(count_distinct_substrings(string))
