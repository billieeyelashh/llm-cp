
def count_distinct_substrings(string):
    n = len(string)
    distinct_substrings = set()
    rolling_hashes = {}

    for i in range(n):
        hash_value = 0
        p = 31  # prime number for hashing
        power = 1

        for j in range(i, n):
            # Calculate the rolling hash of the current substring
            hash_value = (hash_value + (ord(string[j]) - ord('a') + 1) * power) % (10**9 + 7)
            power = (power * p) % (10**9 + 7)

            distinct_substrings.add(hash_value)

    # Print the number of distinct substrings for each length
    for length in range(1, n + 1):
        print(len(distinct_substrings))

# Driver code
string = input().strip()
count_distinct_substrings(string)
