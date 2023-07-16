
n, q = map(int, input().split())
values = list(map(int, input().split()))

prefix = [0] * (n+1)
for i in range(1, n+1):
    prefix[i] = prefix[i-1] + values[i-1]

for _ in range(q):
    a, b = map(int, input().split())
    result = prefix[b] - prefix[a-1] if a > 1 else prefix[b]
    print(result)
