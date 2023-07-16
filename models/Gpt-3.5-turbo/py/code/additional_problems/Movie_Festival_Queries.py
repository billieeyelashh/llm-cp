
from bisect import bisect_left

n, q = map(int, input().split())
movies = []
for _ in range(n):
    a, b = map(int, input().split())
    movies.append((b, a))  # Sorting based on ending time, reverse the order of (a, b)

movies.sort()
max_movies = [0] * n

# Preprocess max_movies
for i in range(n - 1, -1, -1):
    if i == n - 1:
        max_movies[i] = 1
    else:
        max_movies[i] = max(max_movies[i + 1], max_movies[bisect_left(movies, (movies[i][0],)) + 1] + 1)

# Process queries
for _ in range(q):
    a, b = map(int, input().split())
    j = bisect_left(movies, (b,))  # Find the index of the first movie that starts after arrival time
    print(max_movies[j] if j < n else 0)
