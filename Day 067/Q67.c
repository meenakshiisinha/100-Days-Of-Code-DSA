//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
void dfs(int vertex, int *stack, int *top) {
    visited[vertex] = 1;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, stack, top);
        }
    }
    stack[(*top)++] = vertex; // Push vertex to stack after visiting all neighbors
}
void topologicalSort(int numVertices) {
    int stack[MAX_VERTICES];
    int top = 0;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(i, stack, &top);
        }
    }
    // Print the topological order
    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    int numVertices, numEdges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1; // Assuming directed graph
    }
    topologicalSort(numVertices);
    return 0;
}
