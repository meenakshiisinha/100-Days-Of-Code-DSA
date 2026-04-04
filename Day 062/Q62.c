/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // 1-based indexing for vertices
    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Add edge from u to v
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;
        // For undirected graph, add edge from v to u
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    // Print the adjacency lists
    for (int i = 1; i <= n; i++) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    // Free the allocated memory
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];
        while (temp != NULL) {
            struct Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    free(adj);
    return 0;
}

