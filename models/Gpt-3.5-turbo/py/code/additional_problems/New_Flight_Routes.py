
def dfs(node, visited, adj_list):
    visited.add(node)
    for neighbor in adj_list[node]:
        if neighbor not in visited:
            dfs(neighbor, visited, adj_list)

n, m = map(int, input().split())
adj_list = {i: [] for i in range(1, n+1)}

for _ in range(m):
    a, b = map(int, input().split())
    adj_list[a].append(b)

visited = set()
component_count = 0

for city in range(1, n+1):
    if city not in visited:
        component_count += 1
        dfs(city, visited, adj_list)

print(component_count - 1)

for city in range(1, n+1):
    for neighbor in adj_list[city]:
        print(city, neighbor)
