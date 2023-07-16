
def dfs(city, adj_list, visited):
    visited[city] = True
    for neighbor in adj_list[city]:
        if not visited[neighbor]:
            dfs(neighbor, adj_list, visited)

n, m = map(int, input().split())
adj_list = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    adj_list[a].append(b)

visited = [False] * (n+1)
critical_cities = set()

dfs(1, adj_list, visited)

for city in range(1, n+1):
    if not visited[city]:
        continue
    is_critical = True
    for neighbor in adj_list[city]:
        if not visited[neighbor]:
            is_critical = False
            break
    if is_critical:
        critical_cities.add(city)

critical_cities = sorted(critical_cities)

print(len(critical_cities))
print(*critical_cities)
