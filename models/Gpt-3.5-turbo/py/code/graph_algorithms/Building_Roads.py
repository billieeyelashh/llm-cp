
def find(parent, city):
    if parent[city] == city:
        return city
    parent[city] = find(parent, parent[city])  # path compression
    return parent[city]

def merge(parent, rank, city1, city2):
    root1 = find(parent, city1)
    root2 = find(parent, city2)

    if root1 != root2:
        if rank[root1] < rank[root2]:
            parent[root1] = root2
        elif rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root2] = root1
            rank[root1] += 1

def minimum_roads(n, m, roads):
    parent = [i for i in range(n+1)]
    rank = [0] * (n+1)
    result = []

    for road in roads:
        city1, city2 = road
        merge(parent, rank, city1, city2)

    for city in range(1, n+1):
        if find(parent, city) == city:
            result.append(city)

    return len(result) - 1, result[1:]

# Read input
n, m = map(int, input().split())
roads = []
for _ in range(m):
    a, b = map(int, input().split())
    roads.append((a, b))

# Call the function and print the output
k, new_roads = minimum_roads(n, m, roads)
print(k)
for road in new_roads:
    print(*road)
