from collections import deque

def relabel_to_front(graph, source, sink):
    """
    Finds the maximum flow in a flow network using the relabel-to-front algorithm.

    Args:
        graph: A 2D list representing the adjacency matrix of the graph.
        source: The index of the source node.
        sink: The index of the sink node.

    Returns:
        The maximum flow in the network.
    """

    n = len(graph)
    height = [0] * n
    excess = [0] * n
    queue = deque()

    # Initialize heights and excess flow
    height[source] = n
    for v in range(n):
        if v != source:
            excess[v] = graph[source][v]
            if excess[v] > 0:
                queue.append(v)

    # Relabel-to-front algorithm
    while queue:
        u = queue.popleft()
        for v in range(n):
            if graph[u][v] > 0 and height[u] == height[v] + 1:
                flow = min(excess[u], graph[u][v])
                excess[u] -= flow
                excess[v] += flow
                graph[u][v] -= flow
                graph[v][u] += flow
                if excess[v] > 0 and not visited[v]:
                    queue.append(v)
            elif graph[v][u] > 0 and height[v] + 1 == height[u]:
                relabel(graph, height, u, v)
                break

    # Calculate the maximum flow
    max_flow = 0
    for v in range(n):
        max_flow += graph[source][v]

    return max_flow

def relabel(graph, height, u, v):
    """
    Relabels node u in the relabel-to-front algorithm.

    Args:
        graph: The adjacency matrix of the graph.
        height: The height labels of the nodes.
        u: The index of the node to relabel.
        v: A neighbor of node u.
    """

    height[u] = height[v] + 1
    for w in range(n):
        if graph[u][w] > 0 and height[w] + 1 == height[u]:
            excess[u] += graph[u][w]
            excess[w] -= graph[u][w]
            graph[u][w] = 0
            graph[w][u] = graph[u][w]
            if excess[w] > 0 and not visited[w]:
                queue.append(w)