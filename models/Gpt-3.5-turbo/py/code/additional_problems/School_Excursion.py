
def find_parent(parent, x):
    if parent[x] == x:
        return x
    parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_groups(parent, group_size, a, b):
    parent_a = find_parent(parent, a)
    parent_b = find_parent(parent, b)

    if parent_a != parent_b:
        if group_size[parent_a] < group_size[parent_b]:
            parent[parent_a] = parent_b
            group_size[parent_b] += group_size[parent_a]
        else:
            parent[parent_b] = parent_a
            group_size[parent_a] += group_size[parent_b]

def main():
    n, m = map(int, input().split())
    parent = list(range(n+1))
    group_size = [1] * (n+1)

    for _ in range(m):
        a, b = map(int, input().split())
        union_groups(parent, group_size, a, b)

    korkeasaari_count = sum(1 for i in range(1, n+1) if find_parent(parent, i) == i)
    bit_string = ''.join('1' if i <= korkeasaari_count else '0' for i in range(1, n+1))

    print(bit_string)

main()
