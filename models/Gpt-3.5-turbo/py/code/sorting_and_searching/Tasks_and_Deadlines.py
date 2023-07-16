
# Read the input
n = int(input())
tasks = []
for _ in range(n):
    a, d = map(int, input().split())
    tasks.append((a, d))

# Sort the tasks in decreasing order of deadlines
tasks.sort(key=lambda x: x[1], reverse=True)

# Initialize the variables
reward = 0
time = 0

# Process the tasks one by one
for task in tasks:
    a, d = task
    # Check if we can complete the task before its deadline
    if time + a <= d:
        reward += d - (time + a)
        time += a

# Print the maximum reward
print(reward)
