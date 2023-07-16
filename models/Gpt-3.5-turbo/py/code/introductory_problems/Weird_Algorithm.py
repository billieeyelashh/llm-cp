
n = int(input())
print(n, end=' ')  # Print the initial value of n

while n != 1:
    if n % 2 == 0:  # If n is even
        n = n // 2
    else:  # If n is odd
        n = (n * 3) + 1
    print(n, end=' ')  # Print the updated value of n
