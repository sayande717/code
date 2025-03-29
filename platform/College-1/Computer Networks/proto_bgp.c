#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODES 10

// Structure: Route
struct BGPRoute {
    int path[MAX_NODES];
    int path_length;
    int next_hop;
};

// Find out the best path
void bgp_best_path(struct BGPRoute routes[], int num_routes) {
    int best_index = 0;
    int shortest_path = INT_MAX;

    for(int i=0; i<num_routes; i++) {
        if(routes[i].path_length < shortest_path) {
            shortest_path = routes[i].path_length;
            best_index = i;
        }
    }

    printf("\nSelected path: ");
    for(int j=0; j<routes[best_index].path_length; j++) {
        printf("%d ", routes[best_index].path[j]);
    }
    printf("\nNext hop: %d\n", routes[best_index].next_hop);
}

int main() {
    // Define available routes
    struct BGPRoute routes[3] = {
        {{64500, 64501}, 2, 192},
        {{64500, 64502, 64501}, 3, 172},
        {{64500, 64503}, 2, 203}
    };

    bgp_best_path(routes, 3);
    return EXIT_SUCCESS;
}