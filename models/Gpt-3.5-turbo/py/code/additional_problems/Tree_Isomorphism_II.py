
def isomorphic(t1, t2):
    if len(t1) != len(t2):
        return False
    
    if len(t1[1]) != len(t2[1]):
        return False
    
    if len(t1) == 2 and len(t2) == 2:
        return True
    
    for i in range(1, len(t1)):
        found = False
        for j in range(1, len(t2)):
            if isomorphic(t1[t1[i]], t2[t2[j]]):
                found = True
                break
        if not found:
            return False
        
    return True

# Main code
t = int(input())

for _ in range(t):
    n = int(input())
    t1 = [[] for _ in range(n+1)]
    t2 = [[] for _ in range(n+1)]
    
    for _ in range(n-1):
        u, v = map(int, input().split())
        t1[u].append(v)
    
    for _ in range(n-1):
        u, v = map(int, input().split())
        t2[u].append(v)
    
    if isomorphic(t1, t2):
        print("YES")
    else:
        print("NO")
