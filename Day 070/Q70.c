/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    Edge edges[MAX_EDGES];
    int dist[MAX_VERTICES];

    // Read number of vertices and edges
    scanf("%d %d", &n, &m);

    // Read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0; // Assuming source vertex is 0

    // Bellman-Ford algorithm
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");

    return 0;
}
