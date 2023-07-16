
def can_make_products(time, machines, t):
    products_made = 0
    for machine in machines:
        products_made += time // machine
        if products_made >= t:
            return True
    return False

def minimum_time(n, t, machines):
    # Binary search range
    left = min(machines)
    right = max(machines) * t

    # Binary search
    while left < right:
        mid = (left + right) // 2
        if can_make_products(mid, machines, t):
            right = mid
        else:
            left = mid + 1

    return left

# Read input
n, t = map(int, input().split())
machines = list(map(int, input().split()))

# Call the function and print the result
print(minimum_time(n, t, machines))
