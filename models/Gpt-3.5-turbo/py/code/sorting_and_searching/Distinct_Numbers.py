
n = int(input())
values = list(map(int, input().split()))

distinct_values = set(values)
num_distinct = len(distinct_values)

print(num_distinct)
