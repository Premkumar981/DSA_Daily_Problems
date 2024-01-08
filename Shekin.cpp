#include <stdio.h>

#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w] = 1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; ++i) {
        if (adj[v][i] && !visited[i]) {
            DFS(adj, visited, V, i);
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
