
n = int(input())
arr = list(map(int, input().split()))

prefix_xor = [0] * n
prefix_xor[0] = arr[0]

for i in range(1, n):
    prefix_xor[i] = arr[i] ^ prefix_xor[i - 1]

max_xor = 0

for i in range(n):
    for j in range(i):
        max_xor = max(max_xor, prefix_xor[i] ^ prefix_xor[j])

print(max_xor)
