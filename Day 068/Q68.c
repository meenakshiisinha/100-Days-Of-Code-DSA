/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

void topologicalSort(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int inDegree[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Calculate in-degrees of all vertices
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Sort: ");
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        // Decrease in-degree of adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            if (graph[vertex][j] == 1) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int numVertices = 5;

    topologicalSort(graph, numVertices);

    return 0;
}
