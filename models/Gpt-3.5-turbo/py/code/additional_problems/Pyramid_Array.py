
n = int(input())
arr = list(map(int, input().split()))

moves = 0

for i in range(1, n-1):
    if arr[i] < arr[i-1] and arr[i+1] > arr[i]:
        moves += 1
    elif arr[i] > arr[i-1] and arr[i+1] < arr[i]:
        moves += 1

print(moves)
