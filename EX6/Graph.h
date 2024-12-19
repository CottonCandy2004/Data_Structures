#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct EdgeNode {
    int adjvex;
    int weight;
    struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
    char* cityName;
    EdgeNode* firstEdge;
} VertexNode;

typedef struct Graph {
    VertexNode vertices[MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

void InitGraph(Graph* graph);

int AddCity(Graph* graph, const char* cityName);

int FindCity(Graph* graph, const char* cityName);

void CreateEdge(Graph* graph, int start, int end, int time);

void FindShortestPath(Graph* graph, const char* startCity, const char* endCity);

void FreeGraph(Graph* graph);

void InitGraph(Graph* graph) {
    graph->numVertices = 0;
    graph->numEdges = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].cityName = NULL;
        graph->vertices[i].firstEdge = NULL;
    }
}

int AddCity(Graph* graph, const char* cityName) {
    if (graph->numVertices >= MAX_VERTICES) return -1;
    graph->vertices[graph->numVertices].cityName = _strdup(cityName);
    return graph->numVertices++;
}

int FindCity(Graph* graph, const char* cityName) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i].cityName, cityName) == 0) {
            return i;
        }
    }
    return -1;
}

void CreateEdge(Graph* graph, int start, int end, int time) {
    EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
    newEdge->adjvex = end;
    newEdge->weight = time;
    newEdge->next = graph->vertices[start].firstEdge;
    graph->vertices[start].firstEdge = newEdge;
    graph->numEdges++;
}

void FindShortestPath(Graph* graph, const char* startCity, const char* endCity) {
    int start = FindCity(graph, startCity);
    int end = FindCity(graph, endCity);
    if (start == -1 || end == -1) {
        printf("City not found!\n");
        return;
    }

    int* dist = (int*)malloc(graph->numVertices * sizeof(int));
    int* prev = (int*)malloc(graph->numVertices * sizeof(int));
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }
    dist[start] = 0;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int minDist = INT_MAX;
        int u = -1;

        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        EdgeNode* edge = graph->vertices[u].firstEdge;
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

    if (dist[end] == INT_MAX) {
        printf("No path exists from %s to %s\n", startCity, endCity);
    } else {
        printf("Shortest time from %s to %s is %d minutes\n", 
               startCity, endCity, dist[end]);
        printf("Path: ");

        int* path = (int*)malloc(graph->numVertices * sizeof(int));
        int pathLen = 0;
        for (int at = end; at != -1; at = prev[at]) {
            path[pathLen++] = at;
        }

        for (int i = pathLen - 1; i >= 0; i--) {
            printf("%s", graph->vertices[path[i]].cityName);
            if (i > 0) printf(" -> ");
        }
        printf("\n");
        
        free(path);
    }

    free(dist);
    free(prev);
    free(visited);
}

void FreeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].cityName) {
            free(graph->vertices[i].cityName);
        }
        EdgeNode* current = graph->vertices[i].firstEdge;
        while (current) {
            EdgeNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

#endif
