#include <stdio.h>
#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w] = 1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    visited[v] = 1; // Mark the current vertex as visited
    printf("%d ", v); // Print the current vertex
    
    for (int w = 0; w < V; ++w) {
        if (adj[v][w] == 1 && visited[w] == 0) { // Check if there is an edge between v and w and if w has not been visited
            DFS(adj, visited, V, w); // Recursively call DFS with w as the new starting vertex
        }
    }
}

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);
    
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    
    for (int i = 0; i < E; ++i) {
        int v, w;
        scanf("%d %d", &v, &w);
        addEdge(adj, v, w);
    }
    
    int startVertex;
    scanf("%d", &startVertex);
    
    printf("Depth First Traversal starting from vertex %d:\n", startVertex);
    DFS(adj, visited, V, startVertex);
    
    return 0;
}

