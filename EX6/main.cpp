#include "Graph.h"
#include <stdio.h>

int main()
{
    Graph G;
    InitGraph(&G);

    AddCity(&G, "Beijing");
    AddCity(&G, "Shanghai");
    AddCity(&G, "Guangzhou");
    AddCity(&G, "Shenzhen");
    AddCity(&G, "Hangzhou");

    CreateEdge(&G, 0, 1, 150);
    CreateEdge(&G, 1, 0, 150);
    CreateEdge(&G, 1, 2, 120);
    CreateEdge(&G, 2, 3, 30);
    CreateEdge(&G, 1, 4, 45);
    CreateEdge(&G, 4, 2, 90);

    printf("Finding shortest path from Beijing to Shenzhen:\n");
    FindShortestPath(&G, "Beijing", "Shenzhen");

    printf("\nFinding shortest path from Shanghai to Guangzhou:\n");
    FindShortestPath(&G, "Shanghai", "Guangzhou");

    FreeGraph(&G);

    return 0;
}