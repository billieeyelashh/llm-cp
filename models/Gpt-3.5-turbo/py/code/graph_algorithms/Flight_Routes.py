
import heapq

def dijkstra(start, graph):
    n = len(graph)
    distance = [float('inf')] * n
    distance[start] = 0
    heap = [(0, start)]
    routes = [[] for _ in range(n)]

    while heap:
        dist, node = heapq.heappop(heap)
        
        if dist > distance[node]:
            continue
        
        for neighbor, cost in graph[node]:
            new_dist = dist + cost
            if new_dist < distance[neighbor]:
                distance[neighbor] = new_dist
                heapq.heappush(heap, (new_dist, neighbor))
                routes[neighbor] = [node]
            elif new_dist == distance[neighbor]:
                routes[neighbor].append(node)
    
    return routes

def find_k_shortest_routes(n, m, k, flights):
    graph = [[] for _ in range(n)]
    
    for a, b, c in flights:
        graph[a-1].append((b-1, c))
    
    routes = dijkstra(0, graph)
    prices = []
    
    def dfs(node, path):
        if node == n-1:
            prices.append(sum(path))
            if len(prices) == k:
                return
        
        for prev_node in routes[node]:
            dfs(prev_node, path + [graph[prev_node][-1][1]])
            if len(prices) == k:
                return
    
    dfs(n-1, [])
    prices.sort()
    
    return prices[:k]
