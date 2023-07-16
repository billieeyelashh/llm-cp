
n = int(input())

if n == 1:
    print(1)
elif n == 2 or n == 3:
    print("NO SOLUTION")
else:
    # Print all even numbers from 2 to n
    for i in range(2, n+1, 2):
        print(i, end=' ')
    
    # Print all odd numbers from 1 to n
    for i in range(1, n+1, 2):
        print(i, end=' ')
