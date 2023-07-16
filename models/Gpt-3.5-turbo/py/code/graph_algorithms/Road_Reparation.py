
n, m = map(int, input().split())

roads = []
for _ in range(m):
    a, b, c = map(int, input().split())
    roads.append((a, b, c))

roads.sort(key=lambda x: x[2])

parent = [i for i in range(n+1)]

def find_parent(city):
    if parent[city] != city:
        parent[city] = find_parent(parent[city])
    return parent[city]

def union(city1, city2):
    parent1 = find_parent(city1)
    parent2 = find_parent(city2)
    if parent1 != parent2:
        parent[parent2] = parent1

total_cost = 0
edge_count = 0
for road in roads:
    a, b, c = road
    if find_parent(a) != find_parent(b):
        union(a, b)
        total_cost += c
        edge_count += 1
    if edge_count == n-1:
        break

if edge_count == n-1:
    print(total_cost)
else:
    print("IMPOSSIBLE")
