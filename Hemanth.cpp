#include <iostream>
using namespace std;

// Define MAX_N using #define
#define MAX_N 100

int findProminentFigure(int acquaintances[MAX_N][MAX_N], int n) {
    int transitiveClosure[MAX_N][MAX_N];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transitiveClosure[i][j] = acquaintances[i][j];
        }
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool isProminentFigure = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && (transitiveClosure[i][j] || !transitiveClosure[j][i])) {
                isProminentFigure = false;
                break;
            }
        }
        if (isProminentFigure)
            return i;
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> acquaintances[i][j];
        }
    }

    int prominentFigureIndex = findProminentFigure(acquaintances, n);

    if (prominentFigureIndex != -1) {
        cout << "A prominent figure is present at index " << prominentFigureIndex << ".";
    } else {
        cout << "There is no prominent figure in the group.";
    }

    return 0;
}

