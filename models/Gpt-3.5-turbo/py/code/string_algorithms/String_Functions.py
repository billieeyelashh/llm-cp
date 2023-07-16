
def calculate_z_function(s):
    n = len(s)
    z = [0] * n
    l = r = 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[i + z[i]] == s[z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z


def calculate_pi_function(z):
    n = len(z)
    pi = [0] * n
    for i in range(1, n):
        pi[i] = max(pi[i - 1] - 1, z[i])
    return pi


s = input().strip()
z = calculate_z_function(s)
pi = calculate_pi_function(z)
print(' '.join(map(str, z)))
print(' '.join(map(str, pi)))
