
n, a, b = map(int, input().split())
arr = list(map(int, input().split()))

max_sum = float('-inf')
window_sum = 0
window_start = 0

for window_end in range(n):
    window_sum += arr[window_end]

    if window_end - window_start + 1 > b:
        window_sum -= arr[window_start]
        window_start += 1

    if window_end - window_start + 1 >= a:
        max_sum = max(max_sum, window_sum)

print(max_sum)
