
def compute_lps(pattern):
    lps = [0] * len(pattern)
    length = 0  # length of the previous longest prefix suffix

    i = 1
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                # Try to find a smaller prefix that is also a suffix
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

    return lps


def count_occurrences(string, pattern):
    n = len(string)
    m = len(pattern)

    lps = compute_lps(pattern)

    i = 0  # Index for string
    j = 0  # Index for pattern
    count = 0  # Number of occurrences

    while i < n:
        if string[i] == pattern[j]:
            i += 1
            j += 1

            if j == m:
                # Pattern found
                count += 1
                j = lps[j - 1]

        else:
            if j != 0:
                # Try to find a smaller prefix that is also a suffix
                j = lps[j - 1]
            else:
                i += 1

    return count


# Example usage:
string = input()
pattern = input()

result = count_occurrences(string, pattern)
print(result)
