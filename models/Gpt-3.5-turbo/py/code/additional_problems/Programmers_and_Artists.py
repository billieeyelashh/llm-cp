
# Read input
a, b, n = map(int, input().split())
applicants = []
for _ in range(n):
    x, y = map(int, input().split())
    applicants.append((x+y, x, y))

# Sort applicants in descending order of total skills
applicants.sort(reverse=True)

# Counters for the number of hired programmers and artists
p_count = 0
a_count = 0

# Sum of skills
max_skill_sum = 0

# Iterate through applicants
for _, x, y in applicants:
    # Check if the applicant has higher programming skills and we need more programmers
    if p_count < a and x >= y:
        max_skill_sum += x
        p_count += 1
    # Check if the applicant has higher artistic skills and we need more artists
    elif a_count < b and y > x:
        max_skill_sum += y
        a_count += 1

# Print the maximum sum of skills
print(max_skill_sum)
