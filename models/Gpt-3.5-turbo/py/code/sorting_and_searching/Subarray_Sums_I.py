
def count_subarrays(n, x, a):
    count = 0
    window_sum = 0
    left = 0

    for right in range(n):
        window_sum += a[right]

        while window_sum > x:
            window_sum -= a[left]
            left += 1

        if window_sum == x:
            count += 1

    return count

# Read input
n, x = map(int, input().split())
a = list(map(int, input().split()))

# Call the function and print the result
result = count_subarrays(n, x, a)
print(result)
