#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {
    Graph G;

    G.CreateEdge(0, 1);
    G.CreateEdge(0, 2);
    G.CreateEdge(1, 3);
    G.CreateEdge(1, 4);
    G.CreateEdge(2, 5);
    G.CreateEdge(2, 6);
    G.CreateEdge(3, 7);
    G.CreateEdge(4, 7);
    G.CreateEdge(5, 8);
    G.CreateEdge(6, 8);
    G.CreateEdge(7, 9);
    G.CreateEdge(8, 9);
    G.CreateEdge(1, 2);
    G.CreateEdge(3, 4);
    G.CreateEdge(5, 6);
    G.CreateEdge(7, 8);
    G.CreateEdge(2, 4);
    G.CreateEdge(4, 6);
    G.CreateEdge(6, 7);
    G.CreateEdge(8, 7);
    printf("\nDFS Results: ");
    G.DFS();
    printf("\nBFS Results: ");
    G.BFS();

    printf("\n");
    return 0;
}
