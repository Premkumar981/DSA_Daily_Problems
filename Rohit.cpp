#include <iostream>
using namespace std;

#define MAX_FLIGHTS 100

bool canCreateFlightSchedule(int n, int constraints[][2]) {
    // Initialize the adjacency matrix with zeros (no constraints initially)
    int graph[MAX_FLIGHTS][MAX_FLIGHTS] = {0};

    // Set the constraints in the adjacency matrix
    for (int i = 0; i < n; ++i) {
        int flight = constraints[i][0];
        int mustDepartAfter = constraints[i][1];
        graph[flight][mustDepartAfter] = 1;
    }

    // Applying Warshall's algorithm to update the graph
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    // Check if there is a path from any flight to itself (a cycle)
    for (int i = 0; i < n; ++i) {
        if (graph[i][i]) {
            return false; // Not possible to create a valid flight schedule
        }
    }

    return true; // Possible to create a valid flight schedule
}

int main() {
    int n;
    cin >> n;

    int constraints[MAX_FLIGHTS][2];
    for (int i = 0; i < n; ++i) {
        cin >> constraints[i][0] >> constraints[i][1];
    }

    if (canCreateFlightSchedule(n, constraints)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
