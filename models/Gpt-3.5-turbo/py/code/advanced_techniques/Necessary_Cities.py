
def dfs(city):
    visited[city] = True
    for adj_city in adj_list[city]:
        if not visited[adj_city]:
            dfs(adj_city)

n, m = map(int, input().split())

adj_list = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

necessary_cities = []

for city in range(1, n + 1):
    if not visited[city]:
        necessary_cities.append(city)
        dfs(city)

print(len(necessary_cities))
print(*necessary_cities)
