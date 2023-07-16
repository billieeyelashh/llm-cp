
n = int(input())
a = list(map(int, input().split()))

stack = []
ans = []
for i in range(n):
    while stack and stack[-1][0] >= a[i]:
        stack.pop()
    if not stack:
        ans.append(0)
    else:
        ans.append(stack[-1][1])
    stack.append((a[i], i+1))

print(*ans)
