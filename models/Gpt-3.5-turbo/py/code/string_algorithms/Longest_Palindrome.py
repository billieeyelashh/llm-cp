
def longest_palindrome(s):
    n = len(s)
    start = end = 0

    for i in range(n):
        # Check for odd-length palindromes
        left = right = i
        while left >= 0 and right < n and s[left] == s[right]:
            if right - left + 1 > end - start + 1:
                start = left
                end = right
            left -= 1
            right += 1

        # Check for even-length palindromes
        left = i
        right = i + 1
        while left >= 0 and right < n and s[left] == s[right]:
            if right - left + 1 > end - start + 1:
                start = left
                end = right
            left -= 1
            right += 1

    return s[start:end+1]
