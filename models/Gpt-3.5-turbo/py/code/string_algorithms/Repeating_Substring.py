
def is_repeating_substring(s, length):
    seen = set()
    for i in range(len(s) - length + 1):
        substring = s[i:i+length]
        if substring in seen:
            return True
        seen.add(substring)
    return False

def longest_repeating_substring(s):
    low = 1
    high = len(s)
    while low <= high:
        mid = (low + high) // 2
        if is_repeating_substring(s, mid):
            low = mid + 1
        else:
            high = mid - 1
    return s[:low - 1]

# Example usage
s = input().strip()
result = longest_repeating_substring(s)
print(result if result != "" else -1)
