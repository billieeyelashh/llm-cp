
n = int(input())
arr = list(map(int, input().split()))

reversals = []
for i in range(n, 0, -1):
    if arr[i-1] != i:
        j = arr.index(i)
        if j != i-1:
            reversals.append((j+1, i))
        arr = arr[:j] + arr[j:i][::-1] + arr[i:]

print(len(reversals))
for reversal in reversals:
    print(*reversal)
