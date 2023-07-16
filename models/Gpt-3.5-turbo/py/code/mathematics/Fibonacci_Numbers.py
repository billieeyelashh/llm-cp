
MOD = int(1e9) + 7

def multiply_matrices(a, b):
    # Multiply two matrices modulo MOD
    return [[(a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD, (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD],
            [(a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD, (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD]]

def matrix_power(matrix, n):
    # Raise a matrix to the power of n modulo MOD
    if n == 0:
        return [[1, 0], [0, 1]]  # Identity matrix
    elif n % 2 == 0:
        half_power = matrix_power(matrix, n // 2)
        return multiply_matrices(half_power, half_power)
    else:
        return multiply_matrices(matrix, matrix_power(matrix, n - 1))

def fibonacci(n):
    if n <= 1:
        return n
    matrix = [[1, 1], [1, 0]]
    result = matrix_power(matrix, n - 1)
    return result[0][0]

n = int(input())
print(fibonacci(n))
