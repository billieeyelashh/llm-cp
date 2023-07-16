def min_difference():
    n = int(input())
    weights = list(map(int, input().split()))
    total = sum(weights)
    half_total = total / 2

    sums = {0}
    for weight in weights:
        sums |= {x + weight for x in sums}

    print(int(min(abs(half_total - x) for x in sums) * 2))

min_difference()