
n = int(input())
low = 1
high = n * n

while low <= high:
    mid = (low + high) // 2
    count = 0
    for i in range(1, n + 1):
        count += min(mid // i, n)
    
    if count <= (n * n) // 2:
        low = mid + 1
    else:
        high = mid - 1

print(low)
