/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int numVertices;

void DFS(int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i]) {
            if (!visited[i]) {
                parent[i] = vertex;
                DFS(i);
            } else if (i != parent[vertex]) {
                printf("YES\n");
                exit(0);
            }
        }
    }
}
int main() {
    int edges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("NO\n");
    return 0;
}
