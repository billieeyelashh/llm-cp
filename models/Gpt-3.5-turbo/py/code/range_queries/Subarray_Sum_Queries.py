
n, m = map(int, input().split())
arr = list(map(int, input().split()))

max_sum = 0
current_sum = 0

for i in range(n):
    current_sum = max(arr[i], current_sum + arr[i])
    max_sum = max(max_sum, current_sum)
    print(max_sum)

for _ in range(m):
    k, x = map(int, input().split())
    k -= 1
    arr[k] = x

    if current_sum > 0:
        current_sum += x - arr[k]
    else:
        current_sum = max(x, current_sum + x)

    max_sum = max(max_sum, current_sum)
    print(max_sum)
