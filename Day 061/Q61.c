/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // 1-based indexing for vertices
    int **adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }
    // Print the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    // Free the allocated memory
    for (int i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    return 0;
}

