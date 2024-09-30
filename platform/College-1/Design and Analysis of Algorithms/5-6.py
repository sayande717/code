from collections import deque

def bfs(residual_graph, source, sink, parent):
    visited = [False] * len(residual_graph)
    queue = deque([source])
    visited[source] = True

    while queue:
        u = queue.popleft()

        for v in range(len(residual_graph[u])):
            capacity, _ = residual_graph[u][v]
            if not visited[v] and capacity > 0:
                queue.append(v)
                visited[v] = True
                parent[v] = u
                if v == sink:
                    return True

    return False

def bellman_ford(graph, source):
    distance = [float('Inf')] * len(graph)
    parent = [-1] * len(graph)
    distance[source] = 0

    for _ in range(len(graph) - 1):
        for u in range(len(graph)):
            for v, (capacity, cost) in enumerate(graph[u]):
                if capacity > 0 and distance[u] + cost < distance[v]:
                    distance[v] = distance[u] + cost
                    parent[v] = u

    for u in range(len(graph)):
        for v, (capacity, cost) in enumerate(graph[u]):
            if capacity > 0 and distance[u] + cost < distance[v]:
                return parent, v

    return None, None

def cycle_cancelling(graph, source, sink):
    residual_graph = [[(capacity, cost) for capacity, cost in row] for row in graph]
    max_flow = 0
    min_cost = 0

    parent = [-1] * len(graph)
    while bfs(residual_graph, source, sink, parent):
        path_flow = float('Inf')
        s = sink

        while s != source:
            path_flow = min(path_flow, residual_graph[parent[s]][s][0])
            s = parent[s]

        v = sink
        while v != source:
            u = parent[v]
            residual_graph[u][v] = (residual_graph[u][v][0] - path_flow, residual_graph[u][v][1])
            residual_graph[v][u] = (residual_graph[v][u][0] + path_flow, -residual_graph[u][v][1])
            v = parent[v]

        max_flow += path_flow

    while True:
        parent, cycle_start = bellman_ford(residual_graph, source)
        if cycle_start is None:
            break

        cycle = []
        v = cycle_start
        while True:
            cycle.append(v)
            v = parent[v]
            if v == cycle_start and len(cycle) > 1:
                break

        cycle_flow = float('Inf')
        for i in range(len(cycle)):
            u = cycle[i]
            v = cycle[(i + 1) % len(cycle)]
            cycle_flow = min(cycle_flow, residual_graph[u][v][0])

        for i in range(len(cycle)):
            u = cycle[i]
            v = cycle[(i + 1) % len(cycle)]
            residual_graph[u][v] = (residual_graph[u][v][0] - cycle_flow, residual_graph[u][v][1])
            residual_graph[v][u] = (residual_graph[v][u][0] + cycle_flow, -residual_graph[u][v][1])
            min_cost += cycle_flow * residual_graph[u][v][1]

    return max_flow, min_cost

graph = [
    [(0, 0), (16, 2), (13, 1), (0, 0), (0, 0), (0, 0)],
    [(0, 0), (0, 0), (10, 2), (12, 1), (0, 0), (0, 0)],
    [(0, 0), (4, 1), (0, 0), (0, 0), (14, 2), (0, 0)],
    [(0, 0), (0, 0), (9, 1), (0, 0), (0, 0), (20, 2)],
    [(0, 0), (0, 0), (0, 0), (7, 1), (0, 0), (4, 2)],
    [(0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0)]
]
source = 0
sink = 5

max_flow, min_cost = cycle_cancelling(graph, source, sink)
print(f"The maximum possible flow is: {max_flow}")
print(f"The minimum cost of the maximum flow is: {min_cost}")
