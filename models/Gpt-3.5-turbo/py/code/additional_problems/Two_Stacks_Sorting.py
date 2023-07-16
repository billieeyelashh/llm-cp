
n = int(input())
input_list = list(map(int, input().split()))

first_stack = []
second_stack = []
output_list = []

current_number = 1

for number in input_list:
    while (first_stack and first_stack[-1] == current_number):
        output_list.append(first_stack.pop())
        print("1", end=" ")
        current_number += 1
    
    while (second_stack and second_stack[-1] == current_number):
        output_list.append(second_stack.pop())
        print("2", end=" ")
        current_number += 1
    
    if (first_stack and first_stack[-1] < number):
        print("IMPOSSIBLE")
        exit()
    elif (first_stack and first_stack[-1] == number):
        output_list.append(first_stack.pop())
        print("1", end=" ")
        current_number += 1
    else:
        second_stack.append(number)
        print("2", end=" ")

print()
