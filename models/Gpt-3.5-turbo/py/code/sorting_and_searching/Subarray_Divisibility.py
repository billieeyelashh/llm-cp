
n = int(input())
a = list(map(int, input().split()))

prefix = [0] * (n+1)
for i in range(1, n+1):
    prefix[i] = prefix[i-1] + a[i-1]

count = {0: 1}
ans = 0
for i in range(1, n+1):
    rem = prefix[i] % n
    if rem in count:
        ans += count[rem]
    count[rem] = count.get(rem, 0) + 1

print(ans)
