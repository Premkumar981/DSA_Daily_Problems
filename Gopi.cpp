#include <stdio.h>
#include <limits.h>
void add_edge(int adj[][100], int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

int BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[]) {
    int queue[v];
    int front = 0, rear = 0;
    int visited[v];

    for (int i = 0; i < v; ++i) {
        visited[i] = 0;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = 1;
    dist[src] = 0;
    queue[rear++] = src;

    while (front != rear) {
        int u = queue[front++];
        for (int i = 0; i < v; ++i) {
            if (adj[u][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[u] + 1;
                pred[i] = u;
                queue[rear++] = i;

                if (i == dest)
                    return 1; 
            }
        }
    }

    return 0; 
}

void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[]) {
    int path[v];
    int crawl = dest;
    int pathLength = 0;
    path[pathLength++] = crawl;

    while (pred[crawl] != -1) {
        path[pathLength++] = pred[crawl];
        crawl = pred[crawl];
    }

    printf("Shortest path length is: %d\n", dist[dest]);
    printf("Path is: ");
    for (int i = pathLength - 1; i >= 0; i--)
        printf("%d ", path[i]);
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    int adj[100][100] = {0};

    for (int i = 0; i < e; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(adj, src, dest);
    }

    int src, dest;
    scanf("%d %d", &src, &dest);

    int pred[v];
    int dist[v];

    if (BFS(adj, src, dest, v, pred, dist)) {
        printShortestDistance(adj, src, dest, v, pred, dist);
    } else {
        printf("There is no path from %d to %d\n", src, dest);
    }

    return 0;
}
