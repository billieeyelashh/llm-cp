
def find_four_values(n, x, arr):
    for i in range(n):
        for j in range(i+1, n):
            remaining_sum = x - (arr[i] + arr[j])
            visited = set()
            for k in range(n):
                if k != i and k != j:
                    if remaining_sum - arr[k] in visited:
                        return i+1, j+1, k+1, arr.index(remaining_sum - arr[k])+1
                    visited.add(arr[k])
    return "IMPOSSIBLE"

# Read input
n, x = map(int, input().split())
arr = list(map(int, input().split()))

# Call the function and print the output
print(*find_four_values(n, x, arr))
