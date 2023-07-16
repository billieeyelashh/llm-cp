from bisect import bisect_left, bisect_right
from itertools import combinations

def count_sets(arr, target):
    n = len(arr)
    half = n // 2

    # divide the array into two halves
    left = arr[:half]
    right = arr[half:]

    # generate all possible sums of subsets for each half
    left_sums = [sum(comb) for i in range(len(left)+1) for comb in combinations(left, i)]
    right_sums = [sum(comb) for i in range(len(right)+1) for comb in combinations(right, i)]

    # sort the right_sums list
    right_sums.sort()

    # for each sum in the left_sums list, find the number of sums in the right_sums list that make the total sum equal to x
    count = 0
    for left_sum in left_sums:
        rem = target - left_sum
        count += bisect_right(right_sums, rem) - bisect_left(right_sums, rem)

    return count

T = int(input().strip())
results = []
for _ in range(T):
    n, x = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    results.append(count_sets(arr, x))
for result in results:
    print(result)