#include <iostream>

using namespace std;

const int MAX_VERTICES = 100; 
bool isReachable(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    return graph[u][v] == 1;
}

void computeReachability(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    computeReachability(graph, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    int u, v;
    cin >> u >> v;

    if (isReachable(graph, u, v)) {
        cout << "There is a path from vertex " << u << " to vertex " << v << "." << endl;
    } else {
        cout << "There is no path from vertex " << u << " to vertex " << v << "." << endl;
    }

    return 0;
}
