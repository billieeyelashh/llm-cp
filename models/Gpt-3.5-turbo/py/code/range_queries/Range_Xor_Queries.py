
n, q = map(int, input().split())
values = list(map(int, input().split()))

# Calculate prefix xor array
prefix_xor = [0]
for i in range(n):
    prefix_xor.append(prefix_xor[i] ^ values[i])

# Process queries
for _ in range(q):
    a, b = map(int, input().split())
    xor_sum = prefix_xor[b] ^ prefix_xor[a-1]
    print(xor_sum)
