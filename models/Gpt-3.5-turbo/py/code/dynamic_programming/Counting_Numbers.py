
a, b = map(int, input().split())
a_str = str(a)
b_str = str(b)
n = len(b_str)

dp = [[[0] * 2 for _ in range(10)] for _ in range(n+1)]

def countDigits(i, prev, tight):
    if i == n:
        return 1

    if dp[i][prev][tight] != 0:
        return dp[i][prev][tight]

    result = 0
    for d in range(10):
        if d == prev and tight:
            continue
        if not tight and d > int(b_str[i]):
            continue
        if tight and d < int(a_str[i]):
            continue

        next_tight = tight and (d == int(a_str[i])) and (d == int(b_str[i]))
        result += countDigits(i+1, d, next_tight)

    dp[i][prev][tight] = result
    return result

result = countDigits(0, -1, True)
result -= 1
print(result)
