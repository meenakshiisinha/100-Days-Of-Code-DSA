/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void bfs(int graph[MAX][MAX], int n, int s) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // Mark the source node as visited and enqueue it
    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        // Dequeue a vertex from the queue
        int current = queue[front++];
        printf("%d ", current);

        // Explore all adjacent vertices of the dequeued vertex
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark the vertex as visited
                queue[rear++] = i; // Enqueue the vertex
            }
        }
    }
}

int main() {
    int n, s;
    int graph[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    bfs(graph, n, s);

    return 0;
}
