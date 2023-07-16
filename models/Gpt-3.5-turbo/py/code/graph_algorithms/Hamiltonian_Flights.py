
MOD = int(1e9) + 7

def count_routes(n, m, flights):
    count = 0
    visited = [False] * n

    def backtrack(city):
        nonlocal count
        if city == n:
            count += 1
            return
        visited[city] = True
        for next_city in range(n):
            if not visited[next_city] and flights[city][next_city]:
                backtrack(next_city)
        visited[city] = False

    flights = [[False] * n for _ in range(n)]
    for a, b in flights:
        flights[a - 1][b - 1] = True

    backtrack(0)
    return count % MOD

# Read input
n, m = map(int, input().split())
flights = []
for _ in range(m):
    a, b = map(int, input().split())
    flights.append((a, b))

# Count routes and print the result
print(count_routes(n, m, flights))
