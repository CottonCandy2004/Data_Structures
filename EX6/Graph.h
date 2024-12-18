#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <cstdlib>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct EdgeNode {
    int adjvex;     // adjacent vertex index
    int weight;     // edge weight (time)
    struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
    char* cityName;  // name of the city
    EdgeNode* firstEdge;
} VertexNode;

typedef struct Graph {
    VertexNode vertices[MAX_VERTICES];
    int numVertices, numEdges;
    
    Graph() {
        this->numVertices = 0;
        this->numEdges = 0;
        for (int i = 0; i < MAX_VERTICES; i++) {
            this->vertices[i].cityName = nullptr;
            this->vertices[i].firstEdge = nullptr;
        }
    }

    // Add a city to the graph
    int AddCity(const char* cityName) {
        if (numVertices >= MAX_VERTICES) return -1;
        vertices[numVertices].cityName = _strdup(cityName);
        return numVertices++;
    }

    // Find city index by name
    int FindCity(const char* cityName) {
        for (int i = 0; i < numVertices; i++) {
            if (strcmp(vertices[i].cityName, cityName) == 0) {
                return i;
            }
        }
        return -1;
    }

    // Create a directed edge with weight
    void CreateEdge(int start, int end, int time) {
        EdgeNode* newEdge = new EdgeNode;
        newEdge->adjvex = end;
        newEdge->weight = time;
        newEdge->next = vertices[start].firstEdge;
        vertices[start].firstEdge = newEdge;
        numEdges++;
    }

    // Find shortest path using Dijkstra's algorithm
    void FindShortestPath(const char* startCity, const char* endCity) {
        int start = FindCity(startCity);
        int end = FindCity(endCity);
        if (start == -1 || end == -1) {
            printf("City not found!\n");
            return;
        }

        int* dist = new int[numVertices];
        int* prev = new int[numVertices];
        bool* visited = new bool[numVertices];

        // Initialize
        for (int i = 0; i < numVertices; i++) {
            dist[i] = INT_MAX;
            prev[i] = -1;
            visited[i] = false;
        }
        dist[start] = 0;

        // Dijkstra's algorithm
        for (int count = 0; count < numVertices - 1; count++) {
            int minDist = INT_MAX;
            int u = -1;

            // Find vertex with minimum distance
            for (int v = 0; v < numVertices; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            // Update distances of adjacent vertices
            EdgeNode* edge = vertices[u].firstEdge;
            while (edge) {
                int v = edge->adjvex;
                if (!visited[v] && dist[u] != INT_MAX && 
                    dist[u] + edge->weight < dist[v]) {
                    dist[v] = dist[u] + edge->weight;
                    prev[v] = u;
                }
                edge = edge->next;
            }
        }

        // Print result
        if (dist[end] == INT_MAX) {
            printf("No path exists from %s to %s\n", startCity, endCity);
        } else {
            printf("Shortest time from %s to %s is %d minutes\n", 
                   startCity, endCity, dist[end]);
            printf("Path: ");
            
            // Store path
            int* path = new int[numVertices];
            int pathLen = 0;
            for (int at = end; at != -1; at = prev[at]) {
                path[pathLen++] = at;
            }

            // Print path in correct order
            for (int i = pathLen - 1; i >= 0; i--) {
                printf("%s", vertices[path[i]].cityName);
                if (i > 0) printf(" -> ");
            }
            printf("\n");
            
            delete[] path;
        }

        delete[] dist;
        delete[] prev;
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i].cityName) {
                free(vertices[i].cityName);
            }
            EdgeNode* current = vertices[i].firstEdge;
            while (current) {
                EdgeNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
} Graph;

#endif
