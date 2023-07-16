
import heapq

# Step 1: Read input values
n, k = map(int, input().split())
movies = [list(map(int, input().split())) for _ in range(n)]

# Step 2: Sort movies based on end time
movies.sort(key=lambda x: x[1])

# Step 3: Initialize variables
count = 0
end_times = []

# Step 5: Iterate over each movie
for movie in movies:
    start_time, end_time = movie
    
    # Remove movies that have already ended
    while end_times and end_times[0] <= start_time:
        heapq.heappop(end_times)
    
    # If there are still available slots, increment count and add current movie's end time
    if len(end_times) < k:
        count += 1
        heapq.heappush(end_times, end_time)

# Step 6: Print maximum total number of movies
print(count)
