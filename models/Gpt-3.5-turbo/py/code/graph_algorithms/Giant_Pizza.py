
def solve(n, m, wishes):
    toppings = ["+"] * m

    for i in range(n):
        for wish in wishes[i]:
            sign, topping = wish[0], int(wish[1:])
            if sign == "+":
                toppings[topping-1] = "+"
            else:
                toppings[topping-1] = "-"

    return "".join(toppings)

# Read input
n, m = map(int, input().split())
wishes = []
for _ in range(n):
    wishes.append(input().split())

# Solve and print the result
result = solve(n, m, wishes)
print(result)
