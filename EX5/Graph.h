#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdbool.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
    int data;
    EdgeNode* firstEdge;
} VertexNode;

typedef struct Graph {
    VertexNode vertices[MAX_VERTICES];
    int numVertices, numEdges;
    
    Graph() {
        this->numVertices = MAX_VERTICES;
        this->numEdges = 0;
        for (int i = 0; i < this->numVertices; i++) {
            this->vertices[i].data = i;
            this->vertices[i].firstEdge = NULL;
        }
    }
    void CreateEdge(int start, int end) {
        EdgeNode* newEdge = new EdgeNode();
        newEdge->adjvex = end;
        newEdge->next = this->vertices[start].firstEdge;
        this->vertices[start].firstEdge = newEdge;
        this->numEdges++;
    }
    
    void DFS_Recursive(Graph* G, int vertex, bool* visited) {
        visited[vertex] = true;
        printf("%d ", vertex);

        EdgeNode* p = G->vertices[vertex].firstEdge;
        while (p) {
            if (!visited[p->adjvex]) {
                DFS_Recursive(G, p->adjvex, visited);
            }
            p = p->next;
        }
    }

    void DFS() {
        bool* visited = new bool[this->numVertices]();

        DFS_Recursive(this, 0, visited);

        for (int i = 0; i < this->numVertices; i++) {
            if (!visited[i]) {
                DFS_Recursive(this, i, visited);
            }
        }

        delete[] visited;
    }
    void BFS() {
        bool* visited = new bool[this->numVertices]();
        int* queue = new int[this->numVertices];
        int front = 0, rear = 0;

        queue[rear++] = 0;
        visited[0] = true;

        while (front < rear) {
            int vertex = queue[front++];
            printf("%d ", vertex);

            EdgeNode* p = this->vertices[vertex].firstEdge;
            while (p) {
                if (!visited[p->adjvex]) {
                    visited[p->adjvex] = true;
                    queue[rear++] = p->adjvex;
                }
                p = p->next;
            }
        }

        for (int i = 0; i < this->numVertices; i++) {
            if (!visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
                while (front < rear) {
                    int vertex = queue[front++];
                    printf("%d ", vertex);

                    EdgeNode* p = this->vertices[vertex].firstEdge;
                    while (p) {
                        if (!visited[p->adjvex]) {
                            visited[p->adjvex] = true;
                            queue[rear++] = p->adjvex;
                        }
                        p = p->next;
                    }
                }
            }
        }

        delete[] queue;
        delete[] visited;
    }
    ~Graph() {
        for (int i = 0; i < this->numVertices; i++) {
            EdgeNode* p = this->vertices[i].firstEdge;
            while (p) {
                EdgeNode* temp = p;
                p = p->next;
                delete temp;
            }
        }
    }
} Graph;

#endif
