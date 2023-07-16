
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    
    if k == 1:
        print(' '.join(map(str, range(1, n+1))))
    elif k == 2:
        print('2 1', end=' ')
        print(' '.join(map(str, range(3, n+1))))
    else:
        a = list(range(k+1, 0, -1))
        a.extend(range(k+2, n+1))
        print(' '.join(map(str, a)))
