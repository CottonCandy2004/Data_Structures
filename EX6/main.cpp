#include "Graph.h"
#include <stdio.h>

int main()
{
    Graph G;
    
    // Add cities
    G.AddCity("Beijing");
    G.AddCity("Shanghai");
    G.AddCity("Guangzhou");
    G.AddCity("Shenzhen");
    G.AddCity("Hangzhou");

    // Add routes with travel times (in minutes)
    G.CreateEdge(0, 1, 150);  // Beijing -> Shanghai: 150 minutes
    G.CreateEdge(1, 0, 150);  // Shanghai -> Beijing: 150 minutes
    G.CreateEdge(1, 2, 120);  // Shanghai -> Guangzhou: 120 minutes
    G.CreateEdge(2, 3, 30);   // Guangzhou -> Shenzhen: 30 minutes
    G.CreateEdge(1, 4, 45);   // Shanghai -> Hangzhou: 45 minutes
    G.CreateEdge(4, 2, 90);   // Hangzhou -> Guangzhou: 90 minutes

    // Find shortest paths
    printf("Finding shortest path from Beijing to Shenzhen:\n");
    G.FindShortestPath("Beijing", "Shenzhen");

    printf("\nFinding shortest path from Shanghai to Guangzhou:\n");
    G.FindShortestPath("Shanghai", "Guangzhou");

    return 0;
}