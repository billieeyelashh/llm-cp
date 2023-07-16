
n = int(input())
current_food = list(map(int, input().split()))
required_food = list(map(int, input().split()))

excess_food = 0
for i in range(n):
    diff = current_food[i] - required_food[i]
    if diff > 0:
        excess_food += diff

steps = excess_food // n
print(steps)
