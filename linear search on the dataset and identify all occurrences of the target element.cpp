#include <iostream>
using namespace std;

void linearSearch2D(int** arr, int rows, int cols, int target) {
    bool found = false;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                cout << "[" << i << "][" << j << "]";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Element " << target << " not found.";
    }
}

int main() {
    int maxRows, maxCols;

    cin >> maxRows;
    cin >> maxCols;

    int** arr = new int*[maxRows];


    for (int i = 0; i < maxRows; i++) {
        arr[i] = new int[maxCols];
        for (int j = 0; j < maxCols; j++) {
            cin >> arr[i][j];
        }
    }

    int target;
    cin >> target;

    linearSearch2D(arr, maxRows, maxCols, target);

    // Free dynamically allocated memory
    for (int i = 0; i < maxRows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

