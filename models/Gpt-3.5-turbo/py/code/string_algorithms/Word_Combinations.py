
def count_ways(s, k, words):
    n = len(s)
    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        for word in words:
            if s[i - len(word):i] == word:
                dp[i] += dp[i - len(word)]
                dp[i] %= 1000000007

    return dp[n]

# Example usage
s = "ababc"
k = 4
words = ["ab", "abab", "c", "cb"]
print(count_ways(s, k, words))
