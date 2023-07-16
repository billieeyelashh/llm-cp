
def generate_gray_code(n):
    # Base case for n = 1
    if n == 1:
        return ['0', '1']
    
    # Recursive call to generate Gray code for n-1
    prev_gray_code = generate_gray_code(n-1)
    
    # Append '0' to the front of all strings in the previous Gray code
    gray_code = ['0' + code for code in prev_gray_code]
    
    # Reverse the previous Gray code and append '1' to the front of all strings
    gray_code += ['1' + code for code in reversed(prev_gray_code)]
    
    return gray_code

# Read the input
n = int(input())

# Generate the Gray code for n
gray_code = generate_gray_code(n)

# Print the Gray code
for code in gray_code:
    print(code)
