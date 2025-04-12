#include <stdio.h>
#include <limits.h>

#define V 9

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }    
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int parent[]) {
    int sink;
    printf("Source node: 0");
    printf("\nEnter destination node (1-8): "); scanf("%d",&sink);
    printf("\nPath: "); printPath(parent, sink);
    }

// Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];
    int parent[V];

    // Init
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;


    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    // Example Adjacency Matrix of graph for demonstration
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    dijkstra(graph, 0);

    return 0;
}