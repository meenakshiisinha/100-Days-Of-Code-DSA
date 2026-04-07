/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int recStack[MAX_VERTICES];
int numVertices;

int isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < numVertices; i++) {
            if (graph[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int isCyclic() {
    for (int i = 0; i < numVertices; i++) {
        if (isCyclicUtil(i))
            return 1;
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
