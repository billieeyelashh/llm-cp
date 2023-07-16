
n = int(input())
heights = list(map(int, input().split()))

left = 0
right = n - 1
max_area = 0

while left < right:
    width = right - left
    height = min(heights[left], heights[right])
    area = width * height
    max_area = max(max_area, area)

    if heights[left] < heights[right]:
        left += 1
    else:
        right -= 1

print(max_area)
