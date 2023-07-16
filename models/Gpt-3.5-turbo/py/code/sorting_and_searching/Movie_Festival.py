
n = int(input())
movies = []

for _ in range(n):
    a, b = map(int, input().split())
    movies.append((b, a))  # store ending time first for sorting

movies.sort()  # sort movies based on ending time

count = 0
end_time = 0

for movie in movies:
    if movie[1] >= end_time:
        count += 1
        end_time = movie[0]

print(count)
