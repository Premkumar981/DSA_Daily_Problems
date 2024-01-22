#include <stdio.h>
#define INF 10000000
#define MAXN 10

void initialise(int V, int graph[MAXN][MAXN], int dis[MAXN][MAXN], int Next[MAXN][MAXN]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

void floydWarshall(int V, int dis[MAXN][MAXN], int Next[MAXN][MAXN]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void printPath(int path[], int n) {
    for (int i = 0; i < n - 1; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[n - 1]);
}

int main() {
    int V;
    scanf("%d", &V);

    int graph[MAXN][MAXN];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int dis[MAXN][MAXN], Next[MAXN][MAXN];

    initialise(V, graph, dis, Next);
    floydWarshall(V, dis, Next);

    int path[MAXN], count = 0;
    path[count++] = 0;
    int current = 0;

    while (current != V - 1) {
        current = Next[current][V - 1];
        path[count++] = current;
    }

    printf("Shortest path from Source to destination 0: ");
    printPath(path, count);

    return 0;
}

