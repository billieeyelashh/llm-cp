
n = int(input())
reading_times = list(map(int, input().split()))

reading_times.sort()
k_time = 0
j_time = 0
total_time = 0

for i in range(n):
    if k_time <= j_time:
        k_time += reading_times[i]
    else:
        j_time += reading_times[i]
    total_time = max(total_time, max(k_time, j_time))

print(total_time)
