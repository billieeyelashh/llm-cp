
n = int(input())
left_weight = 0
right_weight = 0
left_range = (0, n)
right_range = (0, n)

for _ in range(n):
    c, s = map(int, input().split())
    if s == 1:
        weight_of_moved_coin = left_range[1] - left_range[0] + 1
        left_weight += weight_of_moved_coin
        left_range = (left_weight, left_weight + weight_of_moved_coin - 1)
    else:
        weight_of_moved_coin = right_range[1] - right_range[0] + 1
        right_weight += weight_of_moved_coin
        right_range = (right_weight, right_weight + weight_of_moved_coin - 1)

    if left_range[1] < right_range[0]:
        print('<')
    elif right_range[1] < left_range[0]:
        print('>')
    else:
        print('?')
