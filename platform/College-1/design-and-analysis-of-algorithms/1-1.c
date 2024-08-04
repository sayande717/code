#include <stdbool.h>
#include <stdio.h>
#define NumVertex 6

void printSolution(int color[]);
bool isSafe(int vertex, bool graph[NumVertex][NumVertex], int color[], int inColor) {
    for (int iter = 0; iter < NumVertex; iter++)
        if (graph[vertex][iter] && color[iter]==inColor)
            return false;
    return true;
}

bool graphColoringUtil(bool graph[NumVertex][NumVertex], int numColors, int color[], int vertex) {
    if (vertex == NumVertex) {
        return true;
    }
        
    for (int iterColor = 1; iterColor <= numColors; iterColor++) {
        if (isSafe(vertex, graph, color, iterColor)) {
            color[vertex] = iterColor;

            if (graphColoringUtil(graph, numColors, color, vertex+1) == true) {
                return true;
            }

            color[vertex] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[NumVertex][NumVertex], int numColors) {
    int color[NumVertex];
    for (int iter = 0; iter<NumVertex; iter++) {
        color[iter] = 0;
    }

    if (!graphColoringUtil(graph, numColors, color, 0)) {
        printf("\nSolution not possible with %d colors.",numColors);
        return false;
    }

    printf("\nSolution Possible with %d colors:",numColors);
    printSolution(color);
    return true;
}

void printSolution(int color[]) {
    for (int iter = 0; iter < NumVertex; iter++) {
        printf(" %d ", color[iter]);
    }

    printf("\n");
}

int main() {
    // Static Input: Adjacency Matrix for given graph.
    bool graph[NumVertex][NumVertex] = {
        {0, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
    };

    // FAIL
    graphColoring(graph,3);
    // PASS
    graphColoring(graph,5);

    return 0;
}