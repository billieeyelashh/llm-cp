
def collect_numbers(n, array):
    max_num = 0
    rounds = 0
    for num in array:
        max_num = max(max_num, num)
        if max_num == rounds + 1:
            rounds += 1
    return rounds

# Read input
n = int(input())
array = list(map(int, input().split()))

# Call the function and print the result
print(collect_numbers(n, array))
