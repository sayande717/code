#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_EDGES 10
#define MAX_NODES 5

// network edge
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

// network topology
typedef struct {
    int node_count;
    int edge_count;
    Edge edges[MAX_EDGES];
} Network;

void init_network(Network* net, int nodes) {
    net->node_count = nodes;
    net->edge_count = 0;
}

void add_link(Network* net, int src, int dest, int cost) {
    if(net->edge_count < MAX_EDGES) {
        net->edges[net->edge_count].source = src;
        net->edges[net->edge_count].destination = dest;
        net->edges[net->edge_count].weight = cost;
        net->edge_count++;
    }
}

void bellman_ford(Network* net, int source) {
    int distances[MAX_NODES];
    int predecessors[MAX_NODES];
    
    // Step 1: Initialize distances
    for(int i = 0; i < net->node_count; i++) {
        distances[i] = INT_MAX;
        predecessors[i] = -1;
    }
    distances[source] = 0;

    // Step 2: Relax all edges repeatedly
    for(int i = 1; i < net->node_count; i++) {
        for(int j = 0; j < net->edge_count; j++) {
            int u = net->edges[j].source;
            int v = net->edges[j].destination;
            int weight = net->edges[j].weight;
            
            if(distances[u] != INT_MAX && distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for(int j = 0; j < net->edge_count; j++) {
        int u = net->edges[j].source;
        int v = net->edges[j].destination;
        int weight = net->edges[j].weight;
        
        if(distances[u] != INT_MAX && distances[v] > distances[u] + weight) {
            printf("Network contains negative weight cycle!\n");
            return;
        }
    }

    // Ask for the destination node
    int sink;
    printf("Enter the destination node: ");
    scanf("%d", &sink);

    // Print cost and path to the destination node
    if(sink < 0 || sink >= net->node_count) {
        printf("Invalid\n");
        return;
    }

    printf("\nCost and Path to Node %d\n", sink);
    if(distances[sink] == INT_MAX) {
        printf("Cost: UNREACHABLE\n");
        return;
    }

    printf("Cost: %d\n", distances[sink]);
    printf("Path: ");

    int path[MAX_NODES], index = 0;
    for(int at = sink; at != -1; at = predecessors[at])
        path[index++] = at;

    for(int k = index-1; k >= 0; k--)
        printf("%d ", path[k]);
    printf("\n");
    }


int main() {
    Network net;
    
    // network with no cycles
    init_network(&net, 5);
    add_link(&net, 0, 1, 4);
    add_link(&net, 0, 2, 5);
    add_link(&net, 1, 3, 7);
    add_link(&net, 2, 1, 2);
    add_link(&net, 3, 4, 3);
    add_link(&net, 4, 2, -2);
    bellman_ford(&net, 0);

    return 0;
}
