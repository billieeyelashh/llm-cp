
from collections import defaultdict

def build_graph(n, hierarchy):
    graph = defaultdict(list)
    depth = [0] * (n+1)
    for i in range(2, n+1):
        boss = hierarchy[i-2]
        graph[boss].append(i)
        depth[i] = depth[boss] + 1
    return graph, depth


def preprocess_ancestors(n, graph, depth):
    log_n = 20 # maximum value of log2(n)
    ancestors = [[0] * (log_n+1) for _ in range(n+1)]
    
    for i in range(1, n+1):
        ancestors[i][0] = graph[i]
    
    for j in range(1, log_n+1):
        for i in range(1, n+1):
            if ancestors[i][j-1] != 0:
                ancestors[i][j] = ancestors[ancestors[i][j-1]][j-1]
    
    return ancestors


def find_kth_ancestor(x, k, depth, ancestors):
    log_n = 20 # maximum value of log2(n)
    
    # If k is greater than the depth of employee x, there is no such ancestor
    if k > depth[x]:
        return -1
    
    for j in range(log_n, -1, -1):
        if (1 << j) <= k:
            x = ancestors[x][j]
            k -= (1 << j)
    
    return x


def solve(n, q, hierarchy, queries):
    graph, depth = build_graph(n, hierarchy)
    ancestors = preprocess_ancestors(n, graph, depth)
    
    results = []
    for x, k in queries:
        results.append(find_kth_ancestor(x, k, depth, ancestors))
    
    return results


n, q = 5, 3
hierarchy = [1, 1, 3, 3]
queries = [(4, 1), (4, 2), (4, 3)]

print(solve(n, q, hierarchy, queries))
