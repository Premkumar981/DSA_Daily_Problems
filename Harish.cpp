#include <iostream>
using namespace std;

#define MAX_NODES 100

bool hasChainOfConnections(int n, int connections[MAX_NODES][MAX_NODES], int source, int target) {
    // Applying Warshall's Algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                connections[i][j] = connections[i][j] || (connections[i][k] && connections[k][j]);
            }
        }
    }

    // Check if there exists a connection from source to target
    return connections[source - 1][target - 1];
}

int main() {
    int n;
    cin >> n;

    int connections[MAX_NODES][MAX_NODES] = {0};

    // Input connections matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> connections[i][j];
        }
    }

    int source, target;
    cin >> source >> target;

    // Check for the chain of connections
    if (hasChainOfConnections(n, connections, source, target)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
	
