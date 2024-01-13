#include <stdio.h>
#define INF 1e7
#define MAXN 100

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

void floydWarshall(int V) {
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

void printPath(int source, int destination) {
    printf("Shortest path from Source to destination %d: ", destination);
    printf("%d", source);

    while (source != destination) {
        printf(" -> %d", Next[source][destination]);
        source = Next[source][destination];
    }

    printf("\n");
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

    int destination;
    scanf("%d", &destination);

    initialise(V, graph);
    floydWarshall(V);

    printPath(0, destination);

    return 0;
}

