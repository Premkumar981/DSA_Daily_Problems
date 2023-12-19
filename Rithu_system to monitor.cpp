#include <stdio.h>

#define MAXN 100

int dfs(int node, int adj[][MAXN], int dp[], int vis[], int n) {
    if (vis[node]) {
        return dp[node];
    }

    vis[node] = 1;
    int maxPath = 0;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            int temp = 1 + dfs(i, adj, dp, vis, n);
            if (temp > maxPath) {
                maxPath = temp;
            }
        }
    }

    dp[node] = maxPath;
    return maxPath;
}

void addEdge(int adj[][MAXN], int u, int v) {
    adj[u][v] = 1;
}

int findLongestPath(int adj[][MAXN], int n) {
    int dp[MAXN] = {0};
    int vis[MAXN] = {0};

    int longestPath = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int temp = dfs(i, adj, dp, vis, n);
            if (temp > longestPath) {
                longestPath = temp;
            }
        }
    }

    return longestPath;
}

int main() {
    int n, m;  
    scanf("%d", &n);
    
    int adj[MAXN][MAXN] = {0};
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u - 1, v - 1); 
    }

    printf("%d", findLongestPath(adj, n));
    return 0;
}

