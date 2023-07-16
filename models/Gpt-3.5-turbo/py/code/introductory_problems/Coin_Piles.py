
t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    
    if (a + b) % 3 == 0 and 2 * min(a, b) >= max(a, b):
        print("YES")
    else:
        print("NO")
