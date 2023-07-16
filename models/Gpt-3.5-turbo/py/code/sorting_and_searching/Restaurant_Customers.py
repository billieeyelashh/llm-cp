
n = int(input())
arrivals = []
leavings = []

for _ in range(n):
    a, b = map(int, input().split())
    arrivals.append(a)
    leavings.append(b)

arrivals.sort()
leavings.sort()

max_customers = 0
current_customers = 0
i = 0
j = 0

while i < n and j < n:
    if arrivals[i] < leavings[j]:
        current_customers += 1
        max_customers = max(max_customers, current_customers)
        i += 1
    else:
        current_customers -= 1
        j += 1

print(max_customers)
