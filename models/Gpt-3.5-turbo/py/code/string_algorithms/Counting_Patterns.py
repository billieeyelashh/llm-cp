
def compute_pi(pattern):
    n = len(pattern)
    pi = [0] * n
    j = 0
    
    for i in range(1, n):
        while j > 0 and pattern[i] != pattern[j]:
            j = pi[j-1]
        
        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j
    
    return pi

def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    pi = compute_pi(pattern)
    count = 0
    j = 0
    
    for i in range(n):
        while j > 0 and text[i] != pattern[j]:
            j = pi[j-1]
        
        if text[i] == pattern[j]:
            if j == m - 1:
                count += 1
                j = pi[j]
            else:
                j += 1
    
    return count

# Read input
text = input()
k = int(input())
patterns = [input() for _ in range(k)]

# Process patterns and count occurrences in the string
for pattern in patterns:
    count = kmp_search(text, pattern)
    print(count)
