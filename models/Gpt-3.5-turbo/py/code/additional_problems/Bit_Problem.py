
n = int(input())
arr = list(map(int, input().split()))

for x in arr:
    count_divisible = 0
    count_and = 0
    count_not_zero = 0

    for y in arr:
        if y % x == 0:
            count_divisible += 1
        if (x & y) == x:
            count_and += 1
        if (x & y) != 0:
            count_not_zero += 1

    print(count_divisible, count_and, count_not_zero)
