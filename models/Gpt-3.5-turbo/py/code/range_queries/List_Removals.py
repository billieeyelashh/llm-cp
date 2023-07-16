
n = int(input())
list_contents = list(map(int, input().split()))
positions = list(map(int, input().split()))

removed_elements = []
for i in range(n):
    removed_elements.append(list_contents[positions[i] - 1])
    del list_contents[positions[i] - 1]

print(*removed_elements)
