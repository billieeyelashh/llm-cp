
n, q = map(int, input().split())
array = list(map(int, input().split()))

# Calculate prefix sum array
prefix_sum = [0] * (n+1)
for i in range(1, n+1):
    prefix_sum[i] = prefix_sum[i-1] + array[i-1]

# Process queries
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        a, b, u = query[1:]
        # Update prefix sum array
        prefix_sum[a-1] += u
        prefix_sum[b] -= u
    else:
        k = query[1]
        # Find value at position k
        print(prefix_sum[k] - prefix_sum[k-1])
