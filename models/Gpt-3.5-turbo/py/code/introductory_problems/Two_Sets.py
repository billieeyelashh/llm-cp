
def divide_numbers(n):
    total_sum = n * (n + 1) // 2

    if total_sum % 2 != 0:
        return "NO"

    set1 = []
    set2 = []
    current_sum = 0

    for i in range(n, 0, -1):
        if current_sum + i <= total_sum // 2:
            set1.append(i)
            current_sum += i
        else:
            set2.append(i)

    return "YES\n" + str(len(set1)) + "\n" + " ".join(map(str, set1)) + "\n" + str(len(set2)) + "\n" + " ".join(map(str, set2))

# Example usage:
n = int(input())
print(divide_numbers(n))
