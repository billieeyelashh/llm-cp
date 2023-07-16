
n, k = map(int, input().split())

perm = list(range(1, n+1))
inv = 0

for i in range(n-1, 0, -1):
    if inv + i <= k:
        perm[i], perm[i-1] = perm[i-1], perm[i]
        inv += i

print(*perm)
