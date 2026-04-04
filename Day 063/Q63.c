/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void DFSUtil(int vertex, struct Node** adj, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = adj[vertex];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFSUtil(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // Read edges and build adjacency list
    // ... (code for reading edges and building adjacency list)

    int* visited = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal starting from vertex %d: ", s);
    DFSUtil(s, adj, visited);

    // Free allocated memory
    // ... (code for freeing memory)

    free(visited);
    free(adj);
    return 0;
}

