
n, k = map(int, input().split())
array = list(map(int, input().split()))

low = max(array)
high = sum(array)
result = 0

while low <= high:
    mid = (low + high) // 2
    count = 0
    current_sum = 0
    
    for num in array:
        if current_sum + num > mid:
            count += 1
            current_sum = 0
        current_sum += num
    
    count += 1
    
    if count <= k:
        result = mid
        high = mid - 1
    else:
        low = mid + 1

print(result)
