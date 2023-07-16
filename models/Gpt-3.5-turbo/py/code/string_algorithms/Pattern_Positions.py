
   def hash_string(s):
       p = 31  # prime number
       m = 10**9 + 9  # large prime number
       hash_value = 0
       p_pow = 1

       for char in s:
           hash_value = (hash_value + (ord(char) - ord('a') + 1) * p_pow) % m
           p_pow = (p_pow * p) % m

       return hash_value
   

   for i in range(len(string) - m + 1):
       substring = string[i:i + m]
       hash_value = hash_string(substring)
       hash_table[hash_value] = i + 1
   

   for pattern in patterns:
       hash_value = hash_string(pattern)
       if hash_value in hash_table:
           print(hash_table[hash_value])
       else:
           print(-1)
   