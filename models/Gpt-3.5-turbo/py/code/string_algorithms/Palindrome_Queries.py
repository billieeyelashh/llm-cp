
def is_palindrome(prefix, a, b):
    for i in range(26):  # assuming only lowercase letters
        if prefix[i][b] - prefix[i][a-1] != 0:
            return False
    return True

n, m = map(int, input().split())
s = input()

# initialize the prefix array
prefix = [[0] * (n+1) for _ in range(26)]

# compute cumulative sums
for i in range(1, n+1):
    for j in range(26):
        prefix[j][i] = prefix[j][i-1]
    prefix[ord(s[i-1]) - ord('a')][i] += 1

# process the operations
for _ in range(m):
    op, *args = input().split()
    if op == '1':
        k, x = map(int, args)
        k -= 1  # adjust position to 0-indexed
        prefix[ord(s[k]) - ord('a')][k+1] -= 1
        prefix[x - ord('a')][k+1] += 1
        s = s[:k] + chr(x) + s[k+1:]
    else:
        a, b = map(int, args)
        if is_palindrome(prefix, a, b):
            print('YES')
        else:
            print('NO')
