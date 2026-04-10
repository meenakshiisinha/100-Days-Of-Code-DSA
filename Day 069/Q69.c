/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_VERTICES 100

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_VERTICES];
    int num_edges;
} Graph;

void add_edge(Graph* graph, int src, int dest, int weight) {
    graph[src].edges[graph[src].num_edges].vertex = dest;
    graph[src].edges[graph[src].num_edges].weight = weight;
    graph[src].num_edges++;
}

void dijkstra(Graph* graph, int source, int num_vertices) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int i = 0; i < num_vertices - 1; i++) {
        int min_dist = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < num_vertices; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;

        for (int k = 0; k < graph[min_index].num_edges; k++) {
            Edge edge = graph[min_index].edges[k];
            if (!visited[edge.vertex] && dist[min_index] != INT_MAX &&
                dist[min_index] + edge.weight < dist[edge.vertex]) {
                dist[edge.vertex] = dist[min_index] + edge.weight;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    Graph graph[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i].num_edges = 0;
    }

    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 2, 1);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 3, 5);
    add_edge(graph, 2, 3, 8);

    int source = 0;
    dijkstra(graph, source, MAX_VERTICES);

    return 0;
}
