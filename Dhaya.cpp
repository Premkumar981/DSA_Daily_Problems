#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;

int v, e;
vector<int> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    for (int i = 0; i < v; i++) {
        cout << i << " " ;
    }
    return 0;
}
