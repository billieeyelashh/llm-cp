
def z_algorithm(s):
    n = len(s)
    Z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r:
            Z[i] = min(r - i + 1, Z[i - l])
        while i + Z[i] < n and s[Z[i]] == s[i + Z[i]]:
            Z[i] += 1
        if i + Z[i] - 1 > r:
            l, r = i, i + Z[i] - 1
    return Z

def border_lengths(s):
    n = len(s)
    Z = z_algorithm(s)
    border_lengths = []
    for i in range(1, n):
        if i + Z[i] == n:
            border_lengths.append(Z[i])
    return border_lengths

# Driver code
s = input().strip()
border_lengths = border_lengths(s)
print(' '.join(map(str, border_lengths)))
