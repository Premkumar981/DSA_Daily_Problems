#include <stdio.h>
#define MAX_SIZE 100

int dfs(int adjMatrix[][MAX_SIZE], int n, int start, int end, int visited[MAX_SIZE]){
	if (start == end)
        return 1;
        visited[start] = 1;
        
        for (int i = 0; i < n; ++i){
        	if (adjMatrix[start][i] && !visited[i] && dfs(adjMatrix, n, i, end, visited))
            return 1;
		}
		return 0;
}
int validPath(int n, int edges[][2], int m, int start, int end) {
	int adjMatrix[MAX_SIZE][MAX_SIZE] = {0};
	
	for (int i = 0; i < m; ++i) {
		int u = edges[i][0];
        int v = edges[i][1];
		adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
	}
	int visited[MAX_SIZE] = {0};
	
	return dfs(adjMatrix, n, start, end, visited);
}

int main(){
	int n, m;
    scanf("%d %d", &n, &m);
    
    int edges[MAX_SIZE][2];
    for (int i = 0; i < m; ++i) {
    	scanf("%d %d", &edges[i][0], &edges[i][1]);
	}
	
	int start, end;
    scanf("%d %d", &start, &end);
    
    if (validPath(n, edges, m, start, end)) {
    	printf("There is a path from %d to %d\n", start, end);
	}else{
		printf("There is no path from %d to %d\n", start, end);
	}
	return 0;
}
