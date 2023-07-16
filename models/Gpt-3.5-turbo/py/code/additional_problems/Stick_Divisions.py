
x, n = map(int, input().split())
sticks = list(map(int, input().split()))

# Sort the stick lengths in descending order
sticks.sort(reverse=True)

total_cost = 0

# Repeat until we have the required number of sticks
while len(sticks) < n:
    # Take the longest stick and divide it into two sticks
    longest_stick = sticks.pop(0)
    sticks.append(longest_stick // 2)
    sticks.append(longest_stick - longest_stick // 2)
    # Add the length of the original stick to the total cost
    total_cost += longest_stick

print(total_cost)
